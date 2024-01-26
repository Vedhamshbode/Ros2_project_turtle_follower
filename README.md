# ROS2 Turtle Follower Package

This ROS 2 package includes a launch file and a node that allows you to control one turtle and have another turtle follow it based on its pose in the turtlesim environment.

## Installation

1. Clone this repository to your ROS 2 workspace:

    ```bash
    git clone https://github.com/your-username/your-ros2-turtle-package.git
    ```

2. Build the package:

    ```bash
    colcon build
    ```

3. Source the setup file:

    ```bash
    source install/setup.bash
    ```

## Usage

### Launch the Turtle Follower

To launch the turtle follower along with the turtlesim node, use the provided launch file:

```bash
ros2 launch t_follower_pkg t_follower_launch.py
