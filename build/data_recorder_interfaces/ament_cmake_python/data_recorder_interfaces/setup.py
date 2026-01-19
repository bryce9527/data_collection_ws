from setuptools import find_packages
from setuptools import setup

setup(
    name='data_recorder_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('data_recorder_interfaces', 'data_recorder_interfaces.*')),
)
