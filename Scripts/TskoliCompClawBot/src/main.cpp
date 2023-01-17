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
motor top_left_wheel = motor(TOP_LEFT_PORT);
motor top_right_wheel = motor(TOP_RIGHT_PORT);
motor bottom_right_wheel = motor(BOTTOM_RIGHT_PORT);
motor bottom_left_wheel = motor(BOTTOM_LEFT_PORT);
motor_group left_wheels = motor_group(top_left_wheel,bottom_left_wheel);
motor_group right_wheels = motor_group(top_right_wheel,bottom_right_wheel);
drivetrain chassis(left_wheels,right_wheels,319.024,250,130,distanceUnits::mm,1);
void handleAPress(){
    main_controller.rumble(".");
}
int main() {
    main_controller.ButtonA.pressed( handleAPress );
    while(1) {
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
