/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Fridr                                                     */
/*    Created:      12/01/2023, 16:13:40                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
int32_t TOP_RIGHT_PORT = 1;
int32_t TOP_LEFT_PORT = 11;
int32_t BOTTOM_RIGHT_PORT = 10;
int32_t BOTTOM_LEFT_PORT = 20;
int32_t controller_test = 0;
controller main_controller = controller(primary);
motor29 cageMotor1 = motor29(Brain.ThreeWirePort.A);
motor29 cageMotor2 = motor29(Brain.ThreeWirePort.B);
motor top_left_wheel = motor(TOP_LEFT_PORT);
motor top_right_wheel = motor(TOP_RIGHT_PORT);
motor bottom_right_wheel = motor(BOTTOM_RIGHT_PORT);
motor bottom_left_wheel = motor(BOTTOM_LEFT_PORT);
motor_group left_wheels = motor_group(top_left_wheel,bottom_left_wheel);
motor_group right_wheels = motor_group(top_right_wheel,bottom_right_wheel);
drivetrain chassis(left_wheels,right_wheels,12.6,10,11,distanceUnits::in,1);
task cageTask;
task reverseCageTask;

int cageSpin() {
    while(1){
        cageMotor1.spin(reverse,100,percent);
        cageMotor2.spin(reverse,100,percent);
    }
    return 0;
}
int cageSpinReversed(){
    while(1){
        cageMotor1.spin(fwd,100,percent);
        cageMotor2.spin(fwd,100,percent);
    }
    return 0;
}
void startCage() {
    cageTask.resume();
}
void stopCage(){
    cageMotor1.stop();
    cageMotor2.stop();
    cageTask.suspend();
}

void startCageReverse() {
    reverseCageTask.resume();
}
void stopCageReverse(){
    cageMotor1.stop();
    cageMotor2.stop();
    reverseCageTask.suspend();
}
int main() {
    cageTask = task(cageSpin);
    reverseCageTask = task(cageSpinReversed);
    stopCage();
    stopCageReverse();
    main_controller.ButtonA.pressed(startCage);
    main_controller.ButtonA.released(stopCage);
    main_controller.ButtonB.pressed(startCageReverse);
    main_controller.ButtonB.released(stopCageReverse);
    while(1) {
        this_thread::sleep_for(10);
    }
}
