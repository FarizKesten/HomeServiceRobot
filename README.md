# ROS Home Service Robot Project

## Overview
 A home service robot that can map an environment, navigate to pick up and deliver virtual objects.

## Project Setup
The project consists of the following packages:
* my_robot: This package contains the robot URDF and the robot’s Gazebo launch files.(taken from previous project)
* teleop_twist_keyboard: This package contains a node that will allow you to manually control your robot.
* slam_gmapping: This package contains the Gmapping SLAM node.
* turtlebot_rviz_launchers: This package contains the rviz launch file.
* turtlebot_gazebo: This package contains the turtlebot world launch files.
* turtlebot_teleop: This package contains the keyboard teleop node.
* turtlebot_rviz_launchers: This package contains the rviz launch file.


# # Directories
map: Inside this directory, you will store your gazebo world file and the map generated from SLAM.
scripts: Inside this directory, you’ll store your shell scripts.
rvizConfig: Inside this directory, you’ll store your customized rviz configuration files.
pick_objects: You will write a node that commands your robot to drive to the pickup and drop off zones.
add_markers: You will write a node that model the object with a marker in rviz.
