#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  // ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//修改前
  ros::Subscriber sub = n.subscribe("chatter", 1, chatterCallback);//修改后，改了队列长度，但没有用

  ros::spin();

  return 0;
}

