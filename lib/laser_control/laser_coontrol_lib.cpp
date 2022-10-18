#include "laser_control/laser_control.h"

Laser::Laser(ros::NodeHandle &nh)
    : motor13(1, 13, "/dev/ttyUSB0")
    , motor14(1, 14, "/dev/ttyUSB0")
    , nh_(nh)
{
    ROS_INFO("\n MOVE CLASS CONSTRUCTED\n");

}

Laser::~Laser()
{
    ROS_INFO("\n MOVE CLASS DECONSTRUCTED\n");
}

void Laser::init()
{

    laser_sub = nh_.subscribe("/laser/wheel", 1, &Laser::laser_callback, this);
    endposition();
}

void Laser::laser_callback(const dynamixel_control::wheel_laser &msg)
{
    if(msg.ctrl==1)
    {
        runposition();
    }
    if(msg.ctrl==0)
    {
        endposition();
    }
}

void Laser::runposition()   //laser 支架展開
{
    position13 = 150;
    motor13.setServoState(ON);
    motor13.setSpeed(10);
    motor13.setPosition(position13);
//    cout << "motor13 angle:" << position13 << endl;
   // motor13.waitForIdle();
    //motor13.setServoState(OFF);

    position14 = 152;
    motor14.setServoState(ON);
    motor14.setSpeed(10);
    motor14.setPosition(position14);
    motor14.waitForIdle();
 //   cout << "motor14 angle:" << position14 << endl;
    motor14.setServoState(OFF);

}

void Laser::endposition()   //laser 支架收起
{
    position13 = 73;
    motor13.setServoState(ON);
    motor13.setSpeed(10);
    motor13.setPosition(position13);
  //  cout << "motor13 angle:" << position13 << endl;
    motor13.waitForIdle();
    motor13.setServoState(OFF);

    position14 = 232;
    motor14.setServoState(ON);
    motor14.setSpeed(10);
    motor14.setPosition(position14);
    motor14.waitForIdle();
  //  cout << "motor14 angle:" << position14 << endl;
    motor14.setServoState(OFF);
}
