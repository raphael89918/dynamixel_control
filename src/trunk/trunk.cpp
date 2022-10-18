#include "trunk/trunk.h"

int main(int argc,char** argv)
{
    ros::init(argc,argv,"trunk");
    ros::NodeHandle nh;
    Storage storage(nh);
    storage.init();
    while(ros::ok())
    {
        ros::Rate loop_rate(10);
        ros::spinOnce();
        loop_rate.sleep();
    }

/*
    move.setposition();
    move.gripposition();
   storage.setposition();
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
    move.gripposition();
    storage.pileposition();
//    move.backtoposition();
  */
    return 0;
}

