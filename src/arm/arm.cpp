#include "arm/arm.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"move_cam");
    ros::NodeHandle nh;
    Move move(nh);
    move.setposition();
    move.gripposition();
    ros::Duration(3).sleep();
    move.gripping();
    move.backtoposition();
    ros::Duration(1).sleep();

    move.gripposition();
    ros::Duration(3).sleep();
    move.gripping();
    move.backtoposition();
    ros::Duration(1).sleep();

    move.gripposition();
    ros::Duration(3).sleep();
    move.gripping();
    move.backtoposition();
    return 0;

}

