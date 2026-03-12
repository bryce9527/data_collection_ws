#!/usr/bin/env python3
from flask import Flask, jsonify, Response
from flask_cors import CORS
import subprocess

app = Flask(__name__)
CORS(app)
processes = {}

# Launch camera (dual RealSense)
@app.route("/launch/camera", methods=["POST"])
def launch_camera():
    if "camera" in processes and processes["camera"].poll() is None:
        return jsonify({"status": "camera already launched"})
    p = subprocess.Popen(["ros2", "launch", "data_recorder_ros2", "rs_d435i.launch.py"])
    processes["camera"] = p
    return jsonify({"status": "camera launched"})

@app.route("/kill/camera", methods=["POST"])
def kill_camera():
    p = processes.get("camera")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "camera stopped"})
    return jsonify({"status": "camera not running"})


# Launch glove
@app.route("/launch/glove", methods=["POST"])
def launch_glove():
    if "glove" in processes and processes["glove"].poll() is None:
        return jsonify({"status": "glove already launched"})
    p = subprocess.Popen(
        ["ros2", "launch", "open_cyber_glove_ros2", "glove_joint_state_heartbeat_publisher.launch.py"],
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        bufsize=1
    )
    processes["glove"] = p
    return jsonify({"status": "glove launched"})

@app.route("/logs/glove")
def glove_logs():
    if "glove" not in processes:
        return "Glove not launched", 404
    p = processes["glove"]

    def generate():
        for line in iter(p.stdout.readline, ''):
            yield f"data: {line}\n\n"  # SSE format

    return Response(generate(), mimetype="text/event-stream")

@app.route("/kill/glove", methods=["POST"])
def kill_glove():
    p = processes.get("glove")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "glove stopped"})
    return jsonify({"status": "glove not running"})


# Launch scale
@app.route("/launch/scale", methods=["POST"])
def launch_scale():
    if "scale" in processes and processes["scale"].poll() is None:
        return jsonify({"status": "scale already launched"})
    p = subprocess.Popen(["ros2", "launch", "data_recorder_ros2", "scale.launch.py"])
    processes["scale"] = p
    return jsonify({"status": "scale launched"})

@app.route("/kill/scale", methods=["POST"])
def kill_scale():
    p = processes.get("scale")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "scale stopped"})
    return jsonify({"status": "scale not running"})

# Launch tracker
@app.route("/launch/tracker", methods=["POST"])
def launch_tracker():
    if "tracker" in processes and processes["tracker"].poll() is None:
        return jsonify({"status": "tracker already launched"})
    p = subprocess.Popen(["ros2", "launch", "tracker_bridge", "tracker_bridge.launch.py"])
    processes["tracker"] = p
    return jsonify({"status": "tracker launched"})

@app.route("/kill/tracker", methods=["POST"])
def kill_tracker():
    p = processes.get("tracker")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "tracker stopped"})
    return jsonify({"status": "tracker not running"})

# Launch rosbridge
@app.route("/launch/rosbridge", methods=["POST"])
def launch_rosbridge():
    if "rosbridge" in processes and processes["rosbridge"].poll() is None:
        return jsonify({"status": "rosbridge already launched"})
    p = subprocess.Popen(["ros2", "launch", "rosbridge_server", "rosbridge_websocket_launch.xml", "allow_origin:=*"])
    processes["rosbridge"] = p
    return jsonify({"status": "rosbridge launched"})

@app.route("/kill/rosbridge", methods=["POST"])
def kill_rosbridge():
    p = processes.get("rosbridge")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "rosbridge stopped"})
    return jsonify({"status": "rosbridge not running"})


# Launch data recorder
@app.route("/launch/recorder", methods=["POST"])
def launch_recorder():
    if "recorder" in processes and processes["recorder"].poll() is None:
        return jsonify({"status": "recorder already launched"})
    p = subprocess.Popen(["ros2", "launch", "data_recorder_ros2", "recorder.launch.py"])
    processes["recorder"] = p
    return jsonify({"status": "recorder launched"})

@app.route("/kill/recorder", methods=["POST"])
def kill_recorder():
    p = processes.get("recorder")
    if p and p.poll() is None:
        p.terminate()
        return jsonify({"status": "recorder stopped"})
    return jsonify({"status": "recorder not running"})


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
