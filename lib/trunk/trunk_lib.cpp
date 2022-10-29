#include "trunk/trunk.h"

Storage::Storage(ros::NodeHandle &nh)
    : motor1(1, 0, "/dev/ttyUSB0")
    , motor2(1, 1, "/dev/ttyUSB0")
    , motor3(1, 2, "/dev/ttyUSB0")
    , motor4(1, 3, "/dev/ttyUSB0")
    , motor5(2, 4, "/dev/ttyUSB0")
    , motor6(2, 5, "/dev/ttyUSB0")
    , nh_(nh)
{
    ROS_INFO("\n Storage CLASS CONSTRUCTED\n");
    state_pub = nh.advertise<dynamixel_control::action_state>("/dynamixel/trunk_state",1);
}

Storage::~Storage()
{
    ROS_INFO("\n Storage CLASS DECONSTRUCTED\n");
}

void Storage::init()
{
    Move move(nh_);
    arm_trunk_sub = nh_.subscribe("/dynamixel/arm_storage",1,&Storage::trunk_callback,this);
    dynamixel_control::action_state state_msg;
    state_msg.state = 0;
    state_pub.publish(state_msg);
    oriposition();
    ros::Duration(1).sleep();
    move.setposition();
    state_msg.state = 1;
    state_pub.publish(state_msg);

}

void Storage::trunk_callback(const dynamixel_control::arm_trunk &msg)
{
    dynamixel_control::action_state state_msg;
    state_msg.state = 0;
    state_pub.publish(state_msg);
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);
    motor5.setServoState(ON);
    motor6.setServoState(ON);
    Move move(nh_);
    if(msg.control==1)
    {
        setposition();  //木板傾斜
    }
    if(msg.control==2)
    {
        move.gripping(); //夾取動作
    }
    if(msg.control==3)
    {
        move.backtoposition(); //積木放木板
    }
    if(msg.control==4)
    {
        move.gripposition();    //夾爪放下
    }
    if(msg.control==5)
    {
        pileposition(); //木板積木放置堆疊
    }
    if(msg.control==6)
    {
        oriposition(); //擋板回初始位置
        ros::Duration(1).sleep();
        move.setposition(); //夾爪回初始位置
    }
    state_msg.state = 1;
    state_pub.publish(state_msg);
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
   // cout << "motor3 angle:" << position3 << endl;
    motor3.waitForIdle();
}

void Storage::setposition() //木板傾斜
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);
    motor5.setServoState(ON);
    motor6.setServoState(ON);

    position1 = 133;
    motor1.setServoState(ON);
    motor1.setSpeed(30);
    motor1.setPosition(position1);
    //cout << "motor1 angle:" << position1 << endl;

    position6 = 66;
    motor6.setServoState(ON);
    motor6.setSpeed(30);
    motor6.setPosition(position6);
   // cout << "motor6 angle:" << position6 << endl;

    position2 = 123;
    motor2.setServoState(ON);
    motor2.setSpeed(30);
    motor2.setPosition(position2);
   // cout << "motor2 angle:" << position2 << endl;

    position5 = 333;
    motor5.setServoState(ON);
    motor5.setSpeed(30);
    motor5.setPosition(position5);
   // cout << "motor5 angle:" << position5 << endl;

    position3 = 140;
    motor3.setServoState(ON);
    motor3.setSpeed(30);
    motor3.setPosition(position3);
    //cout << "motor3 angle:" << position3 << endl;

    position4 = 149;
    motor4.setServoState(ON);
    motor4.setSpeed(30);
    motor4.setPosition(position4);
    //cout << "motor4 angle:" << position4 << endl;

    /*  motor1.setServoState(OFF);
        motor2.setServoState(OFF);
        motor3.setServoState(OFF);
        motor4.setServoState(OFF);
        */
}


void Storage::oriposition()
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);
    motor5.setServoState(ON);
    motor6.setServoState(ON);

    position4 = 159;
    motor4.setSpeed(10);
    motor4.setPosition(position4);
  //  cout << "motor4 angle:" << position4 << endl;
    motor4.waitForIdle();

    position3 = 250;
    motor3.setSpeed(10);
    motor3.setPosition(position3);
  //  cout << "motor3 angle:" << position3 << endl;
    motor3.waitForIdle();

    position2 = 91;
    motor2.setSpeed(50);
    motor2.setPosition(position2);
  //  cout << "motor2 angle:" << position2 << endl;
    //motor2.waitForIdle();

    position5 = 303;
    motor5.setSpeed(50);
    motor5.setPosition(position5);
   // cout << "motor5 angle:" << position5 << endl;
    motor5.waitForIdle();

    position6 = 50;
    motor6.setSpeed(50);
    motor6.setPosition(position6);
   // cout << "motor6 angle:" << position6 << endl;
    //motor6.waitForIdle();

    position1 = 134;
    motor1.setSpeed(50);
    motor1.setPosition(position1);
 //   cout << "motor1 angle:" << position1 << endl;
    motor1.waitForIdle();


}


void Storage::pileposition() //木板積木放置堆疊
{
    motor1.setServoState(ON);
    motor2.setServoState(ON);
    motor3.setServoState(ON);
    motor4.setServoState(ON);
    motor5.setServoState(ON);
    motor6.setServoState(ON);

    position3 = 240;
    motor3.setSpeed(10);
    motor3.setPosition(position3);
   // cout << "motor3 angle:" << position3 << endl;
    motor3.waitForIdle();

    position1 = 252;
    motor1.setSpeed(20);
    motor1.setPosition(position1);
   // cout << "motor1 angle:" << position1 << endl;

    position5 = 270;
    motor5.setSpeed(20);
    motor5.setPosition(position5);
  //  cout << "motor5 angle:" << position5 << endl;


    position2 = 52;
    motor2.setSpeed(20);
    motor2.setPosition(position2);
   // cout << "motor2 angle:" << position2 << endl;

    position6 = 171;
    motor6.setSpeed(20);
    motor6.setPosition(position6);
   // cout << "motor6 angle:" << position6 << endl;

    ros::Duration(3).sleep();
    position4 = 59;
    motor4.setSpeed(40);
    motor4.setPosition(position4);
   // cout << "motor4 angle:" << position4 << endl;
    motor4.waitForIdle();

    ros::Duration(1).sleep();
    position3 = 160;
    motor3.setSpeed(10);
    motor3.setPosition(position3);
   // cout << "motor3 angle:" << position3 << endl;

    /*   motor1.setServoState(OFF);
         motor2.setServoState(OFF);
         motor3.setServoState(OFF);
         motor4.setServoState(OFF);
         */
}

