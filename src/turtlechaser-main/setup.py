from setuptools import setup
from glob import glob
import os

package_name = 'turtlechaser'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*launch.[pxy][yma]*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='kalash',
    maintainer_email='kalashjain124@gmail.com',
    description='Police turtle chasing the thieves',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'spawner = turtlechaser.spawner:main',
            'chaser = turtlechaser.controller:main'
        ],
    },
)
