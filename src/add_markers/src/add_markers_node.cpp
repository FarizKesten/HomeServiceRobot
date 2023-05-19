#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include "defines.h"
#include <cmath>

double robot_pose[2];
double distance_thresh = 0.5;


void get_pose(const nav_msgs::Odometry::ConstPtr& msg)
{
  robot_pose[0] = msg->pose.pose.position.x;
  robot_pose[1] = msg->pose.pose.position.y;
}

double calc_dist(double* p1, double* p2)
{
    return sqrt(((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1])));
}

int main( int argc, char** argv )
{
    ros::init(argc, argv, "add_markers");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    ros::Subscriber pose_sub = n.subscribe("odom", 10, get_pose);

    // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::CYLINDER;

    enum State { ORIGIN, PICKED, TARGET } state = ORIGIN; //state of the marker
    while (ros::ok())
    {
        ros::spinOnce(); // get updated value of the robot position
        visualization_msgs::Marker marker;
        // Set the frame ID and timestamp.  See the TF tutorials for information on these.
        marker.header.frame_id = "odom";
        marker.header.stamp = ros::Time::now();

        // Set the namespace and id for this marker.  This serves to create a unique ID
        // Any marker sent with the same namespace and id will overwrite the old one
        marker.ns = "basic_shapes";
        marker.id = 0;

        // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
        marker.type = shape;

        // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
        marker.action = visualization_msgs::Marker::ADD;

        // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
        marker.pose.position.x = 0;
        marker.pose.position.y = 0;
        marker.pose.position.z = 0;
        marker.pose.orientation.x = 0.0;
        marker.pose.orientation.y = 0.0;
        marker.pose.orientation.z = 0.0;
        marker.pose.orientation.w = 1.0;

        marker.scale.x = 0.3;
        marker.scale.y = 0.3;
        marker.scale.z = 0.3;

        // Set the color -- be sure to set alpha to something non-zero!
        marker.color.r = 0.0f;
        marker.color.g = 0.1f;
        marker.color.b = 0.5f;
        marker.color.a = 1.0f;

        marker.lifetime = ros::Duration();

        while (marker_pub.getNumSubscribers() < 1)
        {
            if (!ros::ok())
            {
                return 0;
            }
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }

        double distance;
        switch(state)
        {
            case ORIGIN:
                marker.action = visualization_msgs::Marker::ADD;
                marker.pose.position.x = def::pos[0][0];
                marker.pose.position.y = def::pos[0][1];
                marker_pub.publish(marker);
                ROS_INFO("setting the marker to the origin");
                sleep(5);
                state = PICKED;
                break;
            case PICKED:
                distance = calc_dist(def::pos[0], robot_pose);
                ROS_INFO("distance to pick-up area: %f", distance);
                if( distance < distance_thresh)
                {
                    marker.action = visualization_msgs::Marker::DELETE;
                    marker_pub.publish(marker);
                    ROS_INFO("hiding the marker to the origin");
                    sleep(5);
                    state = TARGET;
                }
                break;
            case TARGET:
                distance = calc_dist(def::pos[1], robot_pose);
                ROS_INFO("distance to target: %f", distance);
                if( distance < distance_thresh)
                {
                    //Publish the marker at the drop off zone
                    marker.action = visualization_msgs::Marker::ADD;
                    marker.pose.position.x = def::pos[1][0];
                    marker.pose.position.y = def::pos[1][1];
                    marker_pub.publish(marker);
                    ROS_INFO("setting the marker to the target");
                    sleep(5);
                }
                break;
        }

    }
}