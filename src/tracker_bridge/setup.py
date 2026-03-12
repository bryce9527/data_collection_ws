from setuptools import find_packages, setup

package_name = 'tracker_bridge'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [ 
            'launch/tracker_bridge.launch.py', 
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nuc',
    maintainer_email='nuc@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'tracker_server = tracker_bridge.tracker_server:main',
            'plot_trackers = tracker_bridge.plot_trackers:main',
        ],
    },
)
