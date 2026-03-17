from setuptools import setup

package_name = 'isaac_arm_ik'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/ik_node.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Bryce Lam',
    maintainer_email='your_email@example.com',
    description='Numerical IK solver for Piper arm in Isaac Sim',
    license='Apache-2.0',
    entry_points={
        'console_scripts': [
            'ik_node = isaac_arm_ik.ik_node:main',
        ],
    },
)
