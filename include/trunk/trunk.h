#ifndef __trunk_H__
#define __trunk_H__

#include <iostream>
#include <string>
#include <ros/ros.h>
#include "arm/arm.h"
#include "dynamixel.h"
#include "dynamixel_control/arm_trunk.h"
#include "dynamixel_control/action_state.h"
using namespace std;

class Storage
{
    public:
        void oriposition();
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
        ros::Publisher state_pub;
        void trunk_callback(const dynamixel_control::arm_trunk &msg);
        Motor motor1;
        Motor motor2;
        Motor motor3;
        Motor motor4;
        Motor motor5;
        Motor motor6;
        int position1;
        int position2;
        int position3;
        int position4;
        int position5;
        int position6;
        string port;

};

#endif
