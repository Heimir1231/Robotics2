using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern signature main_camera__CUBE_ORANGE;
extern signature main_camera__CUBE_PURPLE;
extern signature main_camera__CUBE_GREEN;
extern signature main_camera__SIG_4;
extern signature main_camera__SIG_5;
extern signature main_camera__SIG_6;
extern signature main_camera__SIG_7;
extern vision main_camera;
extern drivetrain Drivetrain;
extern motor_group arms_group;
extern motor29 claw;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );