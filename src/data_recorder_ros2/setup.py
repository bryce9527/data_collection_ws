from setuptools import find_packages, setup

package_name = 'data_recorder_ros2'

setup(
    name=package_name,   # must be underscores, not hyphens
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [ 
            'launch/scale.launch.py', 
            'launch/recorder.launch.py', 
            'launch/data_recorder_bringup.launch.py', 
            'launch/rs_d435i.launch.py',
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='bryce',
    maintainer_email='Bryce.lam@hotmail.com',
    description='Data recorder nodes ported to ROS 2',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'anheng_scale_node = data_recorder_ros2.anheng_scale_node:main',
            'recorder_service = data_recorder_ros2.recorder_service:main',
            'heartbeat_publisher = data_recorder_ros2.heartbeat_publisher:main',
        ],
    },
)
