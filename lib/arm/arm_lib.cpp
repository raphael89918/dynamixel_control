#include "arm/arm.h"

Move::Move(ros::NodeHandle &nh)
    : motor1(1, 6, "/dev/ttyUSB0")
    , motor2(1, 7, "/dev/ttyUSB0")
    , motor3(1, 8, "/dev/ttyUSB0")
    , motor4(1, 9, "/dev/ttyUSB0")
    , motor5(1, 10, "/dev/ttyUSB0")
    , motor6(2, 11, "/dev/ttyUSB0")
    , motor7(2, 12, "/dev/ttyUSB0")
    , nh_(nh)
{
    ROS_INFO("\n MOVE CLASS CONSTRUCTED\n");
}

Move::~Move()
{
    ROS_INFO("\n MOVE CLASS DECONSTRUCTED\n");
}


void Move::setposition() //t初始位置
{
    position1 = 165;
    motor1.setServoState(ON);
    motor1.setSpeed(10);
    motor1.setPosition(position1);
    cout << "motor1 angle:" << position1 << endl;
    motor1.setServoState(OFF);

    motor1.waitForIdle();

    position2 = 155;
    motor2.setServoState(ON);
    motor2.setSpeed(10);
    motor2.setPosition(position2);
    motor2.waitForIdle();
    cout << "motor2 angle:" << position2 << endl;
    motor2.setServoState(OFF);

    position3 = 150;
    motor3.setServoState(ON);
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;
    motor3.setServoState(OFF);

   position4 = 150;
    motor4.setServoState(ON);
    motor4.setSpeed(10);
    motor4.setPosition(position4);
    motor4.waitForIdle();
    cout << "motor4 angle:" << position4 << endl;
    motor4.setServoState(OFF);

    position5 = 220;
    motor5.setServoState(ON);
    motor5.setSpeed(10);
    motor5.setPosition(position5);
    motor5.waitForIdle();
    cout << "motor5 angle:" << position5 << endl;
    motor5.setServoState(OFF);

    position6 = 140;
    motor6.setServoState(ON);
    motor6.setSpeed(50);
    motor6.setPosition(position6);
    cout << "motor6 angle:" << position6 << endl;
    motor6.setServoState(OFF);

    position7 = 160;
    motor7.setServoState(ON);
    motor7.setSpeed(50);
    motor7.setPosition(position7);
    cout << "motor7 angle:" << position7 << endl;
    motor7.setServoState(OFF);
}


void Move::gripposition() //夾取位置
{
    position1 = 70;
    motor1.setServoState(ON);
    motor1.setSpeed(10);
    motor1.setPosition(position1);
    cout << "motor1 angle:" << position1 << endl;
    motor1.setServoState(OFF);

    position2 = 250;
    motor2.setServoState(ON);
    motor2.setSpeed(10);
    motor2.setPosition(position2);
    motor2.waitForIdle();
    cout << "motor2 angle:" << position2 << endl;
    motor2.setServoState(OFF);

    position3 = 220;
    motor3.setServoState(ON);
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;
  //  motor3.setServoState(OFF);

    position4 = 80;
    motor4.setServoState(ON);
    motor4.setSpeed(10);
    motor4.setPosition(position4);
    motor4.waitForIdle();
    cout << "motor4 angle:" << position4 << endl;
   // motor4.setServoState(OFF);

    position5 = 225;
    motor5.setServoState(ON);
    motor5.setSpeed(10);
    motor5.setPosition(position5);
    motor5.waitForIdle();
    cout << "motor5 angle:" << position5 << endl;
   // motor5.setServoState(OFF);

    position6 = 200;
    motor6.setServoState(ON);
    motor6.setSpeed(50);
    motor6.setPosition(position6);
    cout << "motor6 angle:" << position6 << endl;
    motor6.setServoState(OFF);

    position7 = 100;
    motor7.setServoState(ON);
    motor7.setSpeed(50);
    motor7.setPosition(position7);
    motor7.waitForIdle();
    cout << "motor7 angle:" << position7 << endl;
    motor7.setServoState(OFF);
}


void Move::gripping() //夾取動作
{
    position6 = 150;
    motor6.setServoState(ON);
    motor6.setSpeed(50);
    motor6.setPosition(position6);
    cout << "motor6 angle:" << position6 << endl;
    motor6.setServoState(OFF);

    position7 = 150;
    motor7.setServoState(ON);
    motor7.setSpeed(50);
    motor7.setPosition(position7);
    motor7.waitForIdle();
    cout << "motor7 angle:" << position7 << endl;
    motor7.setServoState(OFF);
}

void Move::backtoposition()
{
    position1 = 165;
    motor1.setServoState(ON);
    motor1.setSpeed(10);
    motor1.setPosition(position1);
    cout << "motor1 angle:" << position1 << endl;
    //motor1.setServoState(OFF);

    position2 = 155;
    motor2.setServoState(ON);
    motor2.setSpeed(10);
    motor2.setPosition(position2);
    cout << "motor2 angle:" << position2 << endl;
  //  motor2.setServoState(OFF);

    position3 = 150;
    motor3.setServoState(ON);
    motor3.setSpeed(10);
    motor3.setPosition(position3);
    cout << "motor3 angle:" << position3 << endl;
 //   motor3.setServoState(OFF);

   position4 = 150;
    motor4.setServoState(ON);
    motor4.setSpeed(10);
    motor4.setPosition(position4);
    cout << "motor4 angle:" << position4 << endl;
  //  motor4.setServoState(OFF);

    position5 = 200;
    motor5.setServoState(ON);
    motor5.setSpeed(10);
    motor5.setPosition(position5);
    cout << "motor5 angle:" << position5 << endl;
    motor5.waitForIdle();

    ros::Duration(2).sleep();

    position6 = 200;
    motor6.setServoState(ON);
    motor6.setSpeed(50);
    motor6.setPosition(position6);
    cout << "motor6 angle:" << position6 << endl;

    position7 = 100;
    motor7.setServoState(ON);
    motor7.setSpeed(50);
    motor7.setPosition(position7);
    motor7.waitForIdle();
    cout << "motor7 angle:" << position7 << endl;

    // motor5.setServoState(OFF);

}

void Move::subposition() //夾爪向上轉動
{
  motor5.setServoState(ON);
  position5 = position5 -10;
  motor5.setSpeed(10);
  motor5.setPosition(position5);
}

void Move::addposition() //夾爪向下轉動
{
  motor5.setServoState(ON);
  position5 = position5 +10;
  motor5.setSpeed(10);
  motor5.setPosition(position5);
}
