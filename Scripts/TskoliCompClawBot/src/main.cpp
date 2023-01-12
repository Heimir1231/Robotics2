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
motor top_left_wheel = motor(TOP_LEFT_PORT);
motor top_right_wheel = motor(TOP_RIGHT_PORT);
drivetrain chassis(top_left_wheel,top_right_wheel,101.6,250,130,distanceUnits::mm,1);
int displayTask(){
    while(1){
        Brain.Screen.setCursor(2,1);
        Brain.Screen.print("Left Speed %4.0f",top_left_wheel.velocity(percent));
        Brain.Screen.newLine();
        Brain.Screen.print("Right Speed %4.0f",top_right_wheel.velocity(percent));
        wait(20, timeUnits::msec);
    }
    return 0;
}
int main() {
    task displayInstance(displayTask);
    chassis.setTurnVelocity(50,percent);
    while(1) {
        chassis.turnFor(90,degrees);
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
