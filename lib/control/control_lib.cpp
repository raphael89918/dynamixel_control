#include "control/control.h"


Control::Control(ros::NodeHandle &nh)
    : nh_(nh)
{
    ROS_INFO("\n CONTROL CLASS CONSTRUCTED\n");
}
Control::~Control()
{
    ROS_INFO("\n CONTROL CLASS DECONSTRUCTED\n");
}

void Control::run()
{
    Move move(nh_);
    Storage storage(nh_);
   /*
    while (kbin != 27) {
        kbin = getch();
        if (kbin == 49) {
        move.setposition(); //放下夾爪 木板傾斜
        move.gripposition();
        storage.setposition();
            // keyboard 1
           }
        if (kbin == 50) {
            // keyboard 2
            move.gripping(); //夾取動作
            }
        if (kbin == 51) {
            // keyboard 3
            move.backtoposition(); //積木放木板 夾爪回原位
            move.gripposition();
            }
        if (kbin == 52) {
            // keyboard 4
            storage.pileposition(); //木板積木放置堆疊
            }

        if (kbin == 56) {
            // keyboard 8
            move.subposition(); //夾爪向上轉動
            }
        if (kbin == 57) {
            // keyboard 9
            move.addposition(); //夾爪向下轉動
            }
    }
    */
}
