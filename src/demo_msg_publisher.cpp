#include "ros/ros.h" 
#include "std_msgs/Int32.h" 
#include "std_msgs/String.h" 
#include <iostream> 
int main(int argc, char **argv) 
{ 
 ros::init(argc, argv,"demo_msg_publisher"); 
 ros::NodeHandle node_obj; 
 ros::Publisher number_publisher =  node_obj.advertise<std_msgs::Int32>("/numbers",10); 
 ros::Publisher greeting_publisher =  node_obj.advertise<std_msgs::String>("greeting",10); 
 ros::Rate loop_rate(1); 
 int number_count = 0; 
 while (ros::ok()) 
 { 
  std_msgs::Int32 msg; 
  std_msgs::String msg2;
  msg2.data = "Hello World";
  msg.data = number_count; 
  ROS_INFO("%d",msg.data); 
  ROS_INFO("%s",msg2.data.c_str());
  number_publisher.publish(msg); 
  greeting_publisher.publish(msg2);
  ros::spinOnce(); 
  loop_rate.sleep(); 
  ++number_count; 
 } 
 return 0; 
}

