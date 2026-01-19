from setuptools import find_packages
from setuptools import setup

setup(
    name='open_cyber_glove_ros2',
    version='0.1.0',
    packages=find_packages(
        include=('open_cyber_glove_ros2', 'open_cyber_glove_ros2.*')),
)
