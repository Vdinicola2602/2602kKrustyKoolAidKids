using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor BackRight;
extern motor FrontRight;
extern motor FrontLeft;
extern motor BackLeft;
extern controller Controller1;
extern motor Lift1;
extern motor Lift2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );