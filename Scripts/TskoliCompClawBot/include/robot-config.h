using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group group_arm;
extern motor_group arm_extensions;
extern motor29 Cage1;
extern motor29 Cage2;
extern gyro cage_gyro;
extern motor_group cage_stabilizer;
extern signature main_camera__CUBE_ORANGE;
extern signature main_camera__CUBE_PURPLE;
extern signature main_camera__CUBE_GREEN;
extern signature main_camera__GOAL_RED;
extern signature main_camera__SIG_5;
extern signature main_camera__SIG_6;
extern signature main_camera__SIG_7;
extern vision main_camera;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );