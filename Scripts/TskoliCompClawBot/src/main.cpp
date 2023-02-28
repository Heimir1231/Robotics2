/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Clawbot (Drivetrain) - Template                           */
/*                                                                            */
/*    Name:                                                                   */
/*    Date                                                                    */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    5, 6            
// group_arm            motor_group   1, 10           
// arm_extensions       motor_group   9, 4            
// Cage1                motor29       A               
// Cage2                motor29       B               
// cage_gyro            gyro          H               
// cage_stabilizer      motor_group   2, 8            
// main_camera          vision        3               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
using namespace vex;

int cageLift(){
  while(true){
    if(Controller1.ButtonA.pressing()){
      Cage1.spin(forward,150,percent);
      Cage2.spin(forward,150,percent);
    }
    else if(Controller1.ButtonB.pressing()){
      Cage1.spin(reverse,150,percent);
      Cage2.spin(reverse,150,percent);
    }
    else{
      Cage1.stop();
      Cage2.stop();
    }
    wait(20,msec);
  }
  return 0;
}
int armControll(){
  while(true){
    if(Controller1.Axis2.position(percent) == 0){
      group_arm.stop(hold);
    }
    else{
      group_arm.spin(forward,Controller1.Axis2.position(percent)*2,percent);
    }
    if(Controller1.Axis1.position(percent) == 0){
      arm_extensions.stop(hold);
    }else{
      arm_extensions.spin(forward,Controller1.Axis1.position(percent)*2,percent);
    }
  }
  return 0;
}
int manualStabalize(){
  while(true){
    if(Controller1.ButtonR1.pressing()){cage_stabilizer.spin(forward,20,pct);}
    else if(Controller1.ButtonL1.pressing()){cage_stabilizer.spin(reverse,20,pct);}
    else{cage_stabilizer.stop(hold);}
  }
  return 0;
}

int postInfo(){
  while(true){
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print(group_arm.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print(arm_extensions.position(degrees));
    Brain.Screen.newLine();
    Brain.Screen.print(group_arm.torque(Nm));
    Brain.Screen.newLine();
    Brain.Screen.print(Controller1.Axis2.position(percent));
  }
  return 0;
}
int botVision(){
  while(true){
    
  }
  return 0;
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  group_arm.setRotation(0,degrees);
  /*task stabalize_task(stabalizeCage);*/
  task stabalize_manual(manualStabalize);
  task cage_task(cageLift);
  task arms_task(armControll);
  task info_task(postInfo);
}
