using namespace vex;

extern brain Brain;

// VEXcode devices
extern distance Distance10;
extern motor Motor9;
extern controller Controller1;
extern distance Distance1;
extern potV2 sense;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );