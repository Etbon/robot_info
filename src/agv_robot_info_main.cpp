#include <ros/ros.h>
#include "robot_info/agv_robot_info_class.h"
#include "ros/rate.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "agv_robot_info_node");
    ROS_INFO("Node is online and running...");

    // Create an instance of AGVRobotInfo objenct with all required information
    AGVRobotInfo agvRobotInfo("Blue_42", "B-17242", "181.214.151.129", "3.1.4", "100 Kg", "30 C", "58 %", "250 bar");

    ros::Rate loop_rate(10); // 10 Hz
    while (ros::ok()) {
        agvRobotInfo.publish_data(); // Publish data
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
};