# **TurtleChaser**

## **Idea**
A main turtle (a.k.a. chaser) that will chase the other turtles, spawning only when the previous one is chased.

## **Solution**  
- [x] Creating a controller node that will control the linear and angular velocity of the *chaser turtle* as per the spawning of the other turtles.
- [x] Creating a spawner node that will spawn turtles only when the previous one is chased.
- [x] Using P controller to guide the chaser to the spawned turtle.
- [x] Creating a launch file to launch all the required nodes in one go!

*This package has been created and tested on Ubuntu 22.04 with ROS2 Humble.*

## **How to build**
*Creating a workspace to build the package*
```
mkdir ~/turtlechaser_ws && cd ~/turtlechaser_ws
mkdir src && cd src
```
*Cloning the package*
```
git clone https://github.com/kalashjain23/turtlechaser.git
cd ~/turtlechaser_ws
```
*Installing the dependencies and building the workspace*
```
rosdep install --from-paths src -y --ignore-src
colcon build
```
## **How to use**
```
# building the package
colcon build --packages-select turtlechaser

# source the workspace
source ~/turtlechaser_ws/install/setup.bash

# launch the nodes
ros2 launch turtlechaser turtlechaser.launch.py
```  
*Now you should be enjoying watching a turtle chasing other turtles on its own :D*

https://github.com/kalashjain23/turtlechaser/assets/97672680/782779d1-5e2d-4274-8ac7-a406b8cc8c99
