# ROS Home Service Robot Project

## Overview
 A home service robot that can map an environment, navigate to pick up and deliver virtual objects.

## Project Setup
The project consists of the following packages:
* pick_objects: This package contains module that dictates robot's movement from a pick-up location to a destination
* add_markers: This package contains module that simulates object that will be picked up by the robot and placed to the destination. It contains a state machine that goes from ORIGIN("starting position"), PICKED ("picked up by the robot"), TARGET ("dropped off by the robot at a target destination")
* my_robot: This package contains the robot URDF and the robot’s Gazebo launch files.(taken from previous project)
* teleop_twist_keyboard: This package contains a node that will allow you to manually control your robot.
* slam_gmapping: This package contains the Gmapping's laser-based SLAM (Simultaneously localization And Mapping) node.
* turtlebot_rviz_launchers: This package contains the rviz launch file. This allows us to visualize the robot model, trajectory, and map data.
* turtlebot_gazebo: This package contains the turtlebot world launch files. This allows us to visualize the map and the robot in gazebo. At the same time, the amcl_demo launch file is used to localize the robot (Adaptive Monte Carlo Localization). It uses particle filters to locate the robot within the map.

[video.webm](https://github.com/FarizKesten/HomeServiceRobot/assets/32988360/a713591d-b130-4597-8190-50e9d4edffc1)
