#include "camera_control/camera_control.h"

Camera::Camera(ros::NodeHandle &nh)
    : motor15(1, 15, "/dev/ttyUSB0")
    , nh_(nh)
{
    ROS_INFO("\n CAMERA_CONTROL CLASS CONSTRUCTED\n");
}

Camera::~Camera()
{
    ROS_INFO("\n CAMERA_CONTROL CLASS DECONSTRUCTED\n");
}

void Camera::run()
{
    position15 = 130;
    motor15.setServoState(ON);
    motor15.setSpeed(10);
    motor15.setPosition(position15);
    cout << "motor15 angle:" << position15 << endl;
    //motor15.waitForIdle();
   /*  while (kbin != 27)
    {
        kbin = getch();
        if (kbin == 49) //按1向上轉
        {
            position15 +=10;
        }
        if (kbin == 50) //按2向下轉
        {
           position15 -=10;
        }
        motor15.setPosition(position15);
        cout << "motor15 angle:" << position15 << endl;
    }*/
    motor15.setServoState(OFF);

}
