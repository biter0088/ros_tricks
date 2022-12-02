#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000,true);
  // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  int count = 0;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    //一些放在循环里面的操作--------------------------
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str(); 
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    //------------------------------------------------------

    loop_rate.sleep();
    ++count;//一些放在循环里面的操作
  }


  return 0;
}
