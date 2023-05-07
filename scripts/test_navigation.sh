#/!bin/sh
# in case using the docker image ros v.0.0.6, uncomment the following line
# sudo apt-get install ros-kinetic-turtlebot ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-interactions ros-kinetic-turtlebot-simulator ros-kinetic-kobuki-ftdi ros-kinetic-ar-track-alvar-msgs xterm

# Launch turtlebot
source devel/setup.bash
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/playground.world
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 3

# Launch gmapping demo
source devel/setup.bash
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 3

# Launch rviz
source devel/setup.bash
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 3
