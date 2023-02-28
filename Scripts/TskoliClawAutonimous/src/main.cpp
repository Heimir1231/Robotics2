/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Fridr                                            */
/*    Created:      Thu Feb 23 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// main_camera          vision        3               
// Drivetrain           drivetrain    5, 6            
// arms_group           motor_group   1, 10           
// claw                 motor29       A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
timer dance_time;
int TheDanceOfMyPeople(){
  while(true){
    arms_group.spinFor(reverse,15,degrees,true);
    Drivetrain.turn(right);
  }
  return 0;
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  task autotask(TheDanceOfMyPeople);
}
