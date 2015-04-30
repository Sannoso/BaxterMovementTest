#include "ros/ros.h"
#include "std_msgs/String.h"
#include <cstdlib>
#include <moveit/move_group_interface/move_group.h>

int main(int argc, char **argv)
{
  //initializing and giving the node a name
  ros::init(argc, argv, "Movetest_Node"); 

  ROS_INFO("Booting the Movetest_Node, made by Sander Ruben");
  if(argc != 2)
  {
	ROS_INFO("usage of the Movetest_Node: <# of iterations>");
	return 1;
  }

  //store requested amount of tests in an integer
  static int requestednumberoftests = atoi(argv[1]);

//  printf("%u", requestednumberoftests);
//  printf("%s", argv[1]);
//  ROS_INFO("%s %s", argv[0]," is executed \n the test will be executed a total of ");
//  ROS_INFO("%s %s %s %s", argv[0]," is executed \n the test will be executed a total of ", argv[1]," times \n");


  ROS_INFO("%s %s %u %s", argv[0], " is executed \n  the test will be executed a total of ", requestednumberoftests, " times \n");

  ros::NodeHandle n; //creating NodeHandle called n
  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("Movetestoutput", 1000);

//here I'm creating a client for the IKService, this object is used to call the service later on
//  ros::ServiceClient client = n.serviceClient<>("

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok() & count < requestednumberoftests)
  {
    //CALL IK SERVICE HERE

    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "Testmove " << count << " took X seconds";
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  //ros::shutdown() aan het eind aanroepen om mijn node af te sluiten!

  return 0;
}
