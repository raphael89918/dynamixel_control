#ifndef __trunk_H__
#define __trunk_H__

#include <iostream>
#include <string>
#include <ros/ros.h>
#include "arm/arm.h"
#include "dynamixel.h"
#include "dynamixel_control/arm_trunk.h"
using namespace std;

class Storage
{
    public:
        void run();
        void init();
        void startposition();
        void setposition();
        void pileposition();
        Move move(ros::NodeHandle &nh);
        Storage(ros::NodeHandle &nh);
        ~Storage();
    private:
        ros::NodeHandle nh_;
        ros::Subscriber arm_trunk_sub;
        void trunk_callback(const dynamixel_control::arm_trunk &msg);
        Motor motor1;
        Motor motor2;
        Motor motor3;
        Motor motor4;
        int position1;
        int position2;
        int position3;
        int position4;
        string port;

};

#endif
