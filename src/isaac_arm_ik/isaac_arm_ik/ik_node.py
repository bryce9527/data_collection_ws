import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from piper_msgs.msg import PosCmd
import numpy as np
from piper_sdk.kinematics.piper_fk import C_PiperForwardKinematics


def inverse_kinematics(target_pose, initial_guess=None, max_iters=100, tol=1e-3):
    fk_solver = C_PiperForwardKinematics()
    q = np.zeros(6) if initial_guess is None else np.array(initial_guess)

    for i in range(max_iters):
        cur_pose = fk_solver.CalFK(q)[-1]
        error = np.array(target_pose) - np.array(cur_pose)
        if np.linalg.norm(error) < tol:
            return q

        J = np.zeros((6,6))
        delta = 1e-4
        for j in range(6):
            q_perturb = q.copy()
            q_perturb[j] += delta
            pose_perturb = fk_solver.CalFK(q_perturb)[-1]
            J[:,j] = (np.array(pose_perturb) - np.array(cur_pose)) / delta

        dq = np.linalg.pinv(J).dot(error)
        q += dq

    raise RuntimeError("IK did not converge")

class IKNode(Node):
    def __init__(self):
        super().__init__('ik_node')
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.create_subscription(PosCmd, 'pos_cmd', self.pos_callback, 10)
        self.get_logger().info("IKNode ready: listening to pos_cmd")

    def pos_callback(self, msg: PosCmd):
        target_pose = [msg.x, msg.y, msg.z, msg.roll, msg.pitch, msg.yaw]
        try:
            q = inverse_kinematics(target_pose)
            joint_state = JointState()
            joint_state.name = ['joint1','joint2','joint3','joint4','joint5','joint6']
            joint_state.position = q.tolist()
            self.joint_pub.publish(joint_state)
            self.get_logger().info(f"Published IK solution: {joint_state.position}")
        except RuntimeError as e:
            self.get_logger().warn(str(e))

def main(args=None):
    rclpy.init(args=args)
    node = IKNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
