#include "trunk/trunk.h"

Storage::Storage(ros::NodeHandle &nh)
    : motor1(1, 0, "/dev/ttyUSB0")
    , motor2(1, 1, "/dev/ttyUSB0")
    , motor3(1, 2, "/dev/ttyUSB0")
    , motor4(1, 3, "/dev/ttyUSB0")
    , nh_(nh)
{
    ROS_INFO("\n Storage CLASS CONSTRUCTED\n");
}

Storage::~Storage()
{
    ROS_INFO("\n Storage CLASS DECONSTRUCTED\n");
}

void Storage::init()
{
    arm_trunk_sub = nh_.subscribe("arm_storage",1,&Storage::trunk_callback,this);
}

void Storage::trunk_callback(const dynamixel_control::arm_trunk &msg)
{
     Move move(nh_);
    if(msg.control==1)
    {
        move.setposition(); //放下夾爪 木板傾斜
        move.gripposition();
        setposition();
    }
    if(msg.control==2)
    {
        move.gripping(); //夾取動作
    }
    if(msg.control==3)
    {
        move.backtoposition(); //積木放木板 夾爪回原位
        move.gripposition();
    }
    if(msg.control==4)
    {
        pileposition(); //木板積木放置堆疊
    }
}

void Storage::startposition()
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);

    position3 = 160;
    motor3.setServoState(ON);
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;
    motor3.waitForIdle();
}

void Storage::setposition() //木板傾斜
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);

    position1 = 133;
    motor1.setServoState(ON);
    motor1.setSpeed(30);
    motor1.setPosition(position1);
    cout << "motor1 angle:" << position1 << endl;


    position2 = 123;
    motor2.setServoState(ON);
    motor2.setSpeed(30);
    motor2.setPosition(position2);
    cout << "motor2 angle:" << position2 << endl;

    position3 = 140;
    motor3.setServoState(ON);
    motor3.setSpeed(30);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;

   position4 = 149;
    motor4.setServoState(ON);
    motor4.setSpeed(30);
    motor4.setPosition(position4);
    cout << "motor4 angle:" << position4 << endl;

  /*  motor1.setServoState(OFF);
    motor2.setServoState(OFF);
    motor3.setServoState(OFF);
    motor4.setServoState(OFF);
*/
}


void Storage::run()
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);
  /*  while (kbin != 27) {
        cout << "enter '1' to turn backword,'2'to turn forward " << endl;
        kbin = getch();
        if (kbin == 49) {      // keyboard 1
            position4 = position4 +10 ; // open
            motor4.setSpeed(10);
            motor4.setPosition(position4);
            cout << "motor4 angle:" << position4 << endl;
           }
        if (kbin == 50) {      // keyboard 2
            position4 = position4 -10; // close
            motor4.setSpeed(10);
            motor4.setPosition(position4);
            cout << "motor4 angle:" << position4 << endl;
            }
    }*/
    motor1.setServoState(OFF);
    motor2.setServoState(OFF);
    motor3.setServoState(OFF);
    motor4.setServoState(OFF);

}


void Storage::pileposition() //木板積木放置堆疊
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);

    position3 = 240;
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;
    motor3.waitForIdle();

    position1 = 252;
    motor1.setSpeed(20);
    motor1.setPosition(position1);
    cout << "motor1 angle:" << position1 << endl;


    position2 = 52;
    motor2.setSpeed(20);
    motor2.setPosition(position2);
    cout << "motor2 angle:" << position2 << endl;

    ros::Duration(3).sleep();
    position4 = 59;
    motor4.setSpeed(40);
    motor4.setPosition(position4);
    cout << "motor4 angle:" << position4 << endl;
    motor4.waitForIdle();

    ros::Duration(1).sleep();
    position3 = 160;
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;

    /*   motor1.setServoState(OFF);
    motor2.setServoState(OFF);
    motor3.setServoState(OFF);
    motor4.setServoState(OFF);
*/
}

