#include "control/control.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"control_part");
    ros::NodeHandle nh;
    Control control(nh);
    control.run();
    return 0;
}

