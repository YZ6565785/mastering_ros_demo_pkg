#include "ros/ros.h" 
#include "std_msgs/Int32.h"
#include "std_msgs/String.h" 
#include <iostream> 
void number_callback(const std_msgs::Int32::ConstPtr& msg) { 
   ROS_INFO("Received [%d]",msg->data); 
} 
void greeting_callback(const std_msgs::String::ConstPtr& msg) {
   ROS_INFO("Received greeting [%s]",msg->data.c_str()); 
} 

int main(int argc, char **argv) {  
   ros::init(argc, argv,"demo_msg_subscriber"); 
   ros::NodeHandle node_obj; 
   ros::Subscriber number_subscriber = node_obj.subscribe("/numbers",10,number_callback); 
   ros::Subscriber greeting_subscriber = node_obj.subscribe("greeting",10,greeting_callback); 
   ros::spin();
   return 0; 
}

