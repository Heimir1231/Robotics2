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

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  task cage_task(cageLift);
}
