#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
/*vex-vision-config:begin*/
signature main_camera__CUBE_ORANGE = signature (1, 7091, 8193, 7642, -1715, -1153, -1434, 2.7, 0);
signature main_camera__CUBE_PURPLE = signature (2, 1477, 2647, 2062, 4281, 8193, 6237, 1.5, 0);
signature main_camera__CUBE_GREEN = signature (3, -7525, -2731, -5128, -3073, -957, -2015, 1.2, 0);
vision main_camera = vision (PORT3, 28, main_camera__CUBE_ORANGE, main_camera__CUBE_PURPLE, main_camera__CUBE_GREEN);
/*vex-vision-config:end*/
motor LeftDriveSmart = motor(PORT5, ratio18_1, false);
motor RightDriveSmart = motor(PORT6, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
motor arms_groupMotorA = motor(PORT1, ratio36_1, false);
motor arms_groupMotorB = motor(PORT10, ratio36_1, true);
motor_group arms_group = motor_group(arms_groupMotorA, arms_groupMotorB);
motor29 claw = motor29(Brain.ThreeWirePort.A, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}