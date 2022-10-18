#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <iostream>
#include <string>
#include <ros/ros.h>
#include "dynamixel.h"
#include "arm/arm.h"
#include "trunk/trunk.h"

using namespace std;

class Control
{
    public:

        Control(ros::NodeHandle &nh);
        ~Control();
        Move move(ros::NodeHandle &nh);
        Storage storage(ros::NodeHandle &nh);
        void run();

    private:
        ros::NodeHandle nh_;

};

#endif
