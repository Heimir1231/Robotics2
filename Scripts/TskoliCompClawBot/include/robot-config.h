using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group group_arm;
extern motor_group arm_extensions;
extern motor29 right_arm_3wire;
extern motor29 left_arm_3wire;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );