# ROS2 Turtle Follower Package

There are two ROS 2 packages in this repository. t_follower_pkg includes a launch file and a node that allows you to control one turtle and have another turtle follow it based on its pose in the turtlesim environment. While we will be able to control the first turtle.

The second package is turtkechaser. A main turtle (a.k.a. chaser) that will chase the other turtles, spawning only when the previous one is chased

*These packages have been created and tested on Ubuntu 22.04 with ROS2 Humble.*


## Installation

1. Clone this repository to your ROS 2 workspace:

    ```bash
    git clone https://github.com/your-username/your-ros2-turtle-package.git
    ```

2. Build the package:

    ```bash
    rosdep install --from-paths src -y --ignore-src
    colcon build
    ```

3. Source the setup file:

    ```bash
    source install/setup.bash
    ```

## Usage of Turtle_follower

### Launch the Turtle Follower

To launch the turtle follower along with the turtlesim node, use the provided launch file:

```bash
ros2 launch t_follower_pkg t_follower_launch.py
```

## Solution  
Creating a controller node that will control the linear and angular velocity of the *chaser turtle* as per the spawning of the other turtles.
Creating a spawner node that will spawn turtles only when the previous one is chased.
Using P controller to guide the chaser to the spawned turtle.
Creating a launch file to launch all the required nodes in one go!

## Usage of turtlechaser
```
# building the package
colcon build --packages-select turtlechaser

# source the workspace
source ~/turtlechaser_ws/install/setup.bash

# launch the nodes
ros2 launch turtlechaser turtlechaser.launch.py
```  
*Now you should be enjoying watching a turtle chasing other turtles on its own :D*
