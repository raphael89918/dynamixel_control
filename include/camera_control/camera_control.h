#ifndef __CAMERA_CONTROL_H__
#define __CAMERA_CONTROL_H__

#include <iostream>
#include <string>
#include <ros/ros.h>
#include "dynamixel.h"
using namespace std;

class Camera
{
    public:
        void run();
        Camera(ros::NodeHandle &nh);
        ~Camera();
    private:
        ros::NodeHandle nh_;
        Motor motor15;
        int position15;
        string port;
};

#endif
