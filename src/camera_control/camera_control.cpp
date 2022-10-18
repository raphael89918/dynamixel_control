#include "camera_control/camera_control.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"camera_control");
    ros::NodeHandle nh;
    Camera camera(nh);
    camera.run();
    return 0;
}

