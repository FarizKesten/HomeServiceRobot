
#/!bin/sh
# in case using the docker image ros v.0.0.6, uncomment the following line
# sudo apt-get install ros-kinetic-turtlebot ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-interactions ros-kinetic-turtlebot-simulator ros-kinetic-kobuki-ftdi ros-kinetic-ar-track-alvar-msgs xterm

# Launch turtlebot
source devel/setup.bash
export TURTLEBOT_GAZEBO_WORLD_FILE="$(pwd)/src/my_robot/worlds/office.world"
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 3

# Launch amcl demo
source devel/setup.bash
export TURTLEBOT_GAZEBO_MAP_FILE="$(pwd)/src/my_robot/maps/office.yaml"
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 3

# Launch rviz
source devel/setup.bash
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 3

# Launch add_markers
source devel/setup.bash
xterm -e " rosrun add_markers add_markers_node " &
sleep 3
