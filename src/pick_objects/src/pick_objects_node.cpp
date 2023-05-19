#include "defines.h"
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


void send_robot_to_position(MoveBaseClient & ac, double x, double y, double rotZ) {

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  // goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.frame_id = "odom";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.orientation.z = rotZ;
  goal.target_pose.pose.orientation.w = (1.0 - rotZ * rotZ);

  // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal to  x:%f y:%f z:%f", x, y, rotZ);
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, arrived at goal");
  else
    ROS_INFO("The base failed to arrive at goal for some reason");

}

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  send_robot_to_position(ac, def::pos[0][0], def::pos[0][1], def::pos[0][2]);
  ROS_INFO("Successfully reached the first position");
  sleep(5); // wait after the pickup-zone is reached
  send_robot_to_position(ac, def::pos[1][0], def::pos[1][1], def::pos[1][2]);
  ROS_INFO("Successfully reached the second position");
  return 0;
}
