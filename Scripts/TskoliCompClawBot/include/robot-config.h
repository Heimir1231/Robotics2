using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern drivetrain Drivetrain;
extern motor_group group_arm;
extern motor_group arm_extensions;
extern motor29 Cage1;
extern motor29 Cage2;
extern gyro cage_gyro;
extern motor_group cage_stabilizer;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );