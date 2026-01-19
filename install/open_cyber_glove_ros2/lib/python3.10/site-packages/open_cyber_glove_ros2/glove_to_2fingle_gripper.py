#!/home/bryce/anaconda3/envs/ocg/bin/python
# -*- coding: utf-8 -*-

import time
import signal
import rospy
from std_msgs.msg import Float32

from open_cyber_glove.sdk import OpenCyberGlove

def normalize_inverted(raw, vmin, vmax):
    denom = (vmax - vmin)
    if denom == 0:
        return 0.0
    x = (raw - vmin) / float(denom)
    x = 1.0 - max(0.0, min(1.0, x))  # invert so "bend more" => higher value
    return x

def get_grasp_signal(raw_data, min_vals, max_vals,
                     thumb_idxs=(1, 0), index_idxs=(4, 5),
                     coeff_thumb=1.0, coeff_index=1.0,
                     deadband=0.03):
    vals = []
    for i in thumb_idxs:
        vals.append(normalize_inverted(raw_data[i], min_vals[i], max_vals[i]))
    for i in index_idxs:
        vals.append(normalize_inverted(raw_data[i], min_vals[i], max_vals[i]))
    avg = sum(vals) / max(1, len(vals))
    # simple gain per group if needed
    weighted = (coeff_thumb * (sum(vals[:len(thumb_idxs)]) / max(1, len(thumb_idxs))) +
                coeff_index * (sum(vals[len(thumb_idxs):]) / max(1, len(index_idxs))))
    # normalize back to [0,1]
    denom = (coeff_thumb + coeff_index)
    grasp = weighted / denom if denom > 0 else avg
    # deadband to reduce jitter
    if abs(grasp) < deadband:
        grasp = 0.0
    return max(0.0, min(1.0, grasp))

class GracefulExit(object):
    def __init__(self):
        self.stop = False
        signal.signal(signal.SIGINT, self._handler)
        signal.signal(signal.SIGTERM, self._handler)
    def _handler(self, *_):
        self.stop = True

def main(glove_serial_port="/dev/ttyUSB0", rate_hz=50.0):
    rospy.init_node("glove_to_gripper")
    pub = rospy.Publisher("/gripper_command", Float32, queue_size=10)
    r = rospy.Rate(rate_hz)

    glove = OpenCyberGlove(left_port=glove_serial_port)
    glove.start()
    glove.calibrate()
    time.sleep(0.5)

    shutdown = GracefulExit()
    rospy.loginfo("Start teleoperation: thumb+index control -> /gripper_command [0..1]")
    prev = 0.0
    alpha = rospy.get_param("~smoothing_alpha", 0.2)  # 0=no smoothing, 1=all smoothing

    while not rospy.is_shutdown() and not shutdown.stop:
        data = glove.get_data(hand_type='left')
        raw = data.tensile_data
        min_vals = glove.left_glove.min_val
        max_vals = glove.left_glove.max_val

        grasp = get_grasp_signal(raw, min_vals, max_vals,
                                 thumb_idxs=tuple(rospy.get_param("~thumb_idxs", [1, 0])),
                                 index_idxs=tuple(rospy.get_param("~index_idxs", [4, 5])),
                                 coeff_thumb=rospy.get_param("~coeff_thumb", 1.0),
                                 coeff_index=rospy.get_param("~coeff_index", 1.0),
                                 deadband=rospy.get_param("~deadband", 0.03))

        # exponential smoothing to reduce jitter
        smoothed = alpha * grasp + (1.0 - alpha) * prev
        prev = smoothed

        pub.publish(Float32(data=smoothed))
        r.sleep()

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Teleop OpenCyberGlove -> 2-finger gripper (ROS topic).")
    parser.add_argument("--glove_serial_port", type=str, default="/dev/ttyUSB0",
                        help="Serial port for OpenCyberGlove (default: /dev/ttyUSB0)")
    parser.add_argument("--rate_hz", type=float, default=50.0, help="Publish rate (Hz)")
    args = parser.parse_args()
    main(glove_serial_port=args.glove_serial_port, rate_hz=args.rate_hz)
