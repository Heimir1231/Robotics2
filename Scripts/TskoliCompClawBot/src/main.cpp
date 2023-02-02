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
// Drivetrain           drivetrain    1, 10           
// group_arm            motor_group   8, 7            
// arm_extensions       motor_group   6, 5            
// right_arm_3wire      motor29       C               
// left_arm_3wire       motor29       D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
triport ThreeWirePort = triport(PORT22);
motor29 Cage1(ThreeWirePort.A);
motor29 Cage2(ThreeWirePort.B);
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
    if(Controller1.Axis1.position(percent) == 0){
      group_arm.stop(hold);
      right_arm_3wire.stop();
      left_arm_3wire.stop();
    }
    else{
      group_arm.spin(forward,Controller1.Axis1.position(percent),pct);
      if(Controller1.Axis1.position(percent) > 0){
        right_arm_3wire.spin(forward);
        left_arm_3wire.spin(forward);
      }else{
        right_arm_3wire.stop();
        left_arm_3wire.stop();
      }
    }
    if(Controller1.Axis2.position(percent) == 0){
      arm_extensions.stop(hold);
    }else{
      arm_extensions.spin(forward,Controller1.Axis2.position(percent),pct);
    }
  }
  return 0;
}
int postInfo(){
  while(true){
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print(Controller1.Axis1.position(percent));
  }
  return 0;
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  group_arm.setRotation(0,degrees);
  task cage_task(cageLift);
  task arms_task(armControll);
  task info_task(postInfo);
}
