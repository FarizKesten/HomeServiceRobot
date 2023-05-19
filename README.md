# ROS Home Service Robot Project

## Overview
 A home service robot that can map an environment, navigate to pick up and deliver virtual objects.

## Project Setup
The project consists of the following packages:
* pick_objects: This package contains module that dictates robot's movement from a pick-up location to a destination
* add_markers: This package contains module that simulates object that will be picked up by the robot and places to the destination
* my_robot: This package contains the robot URDF and the robot’s Gazebo launch files.(taken from previous project)
* teleop_twist_keyboard: This package contains a node that will allow you to manually control your robot.
* slam_gmapping: This package contains the Gmapping SLAM node.
* turtlebot_rviz_launchers: This package contains the rviz launch file.
* turtlebot_gazebo: This package contains the turtlebot world launch files.
* turtlebot_teleop: This package contains the keyboard teleop node.
* turtlebot_rviz_launchers: This package contains the rviz launch file.

