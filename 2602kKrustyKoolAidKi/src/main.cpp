/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\first                                            */
/*    Created:      Wed Sep 18 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
// need to find out how to declare graphics functions #include "vex"
using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
// Port Values for driving motors & Controller
vex::motor BackRight        = vex::motor( vex::PORT3);
vex::motor FrontRight        = vex::motor(vex::PORT4);
vex::motor FrontLeft      = vex::motor(vex::PORT1); 
vex::motor BackLeft       = vex::motor(vex::PORT2);
vex::controller ControllerMain = vex::controller();
vex::motor Claw1          = vex::motor(Port);
vex::motor Claw2          = vex::motor(Port);
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
//  graphics()
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  Brain.Screen.print("Autobots Activated");
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  Brain.Screen.print("Driving Mode Activated");
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.
        // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
    if(Axis3){
      
      //Axis 3 controlleing left wheels
      BackLeft.spin(vex::directionType::fwd, ControllerMain.Axis3.position(), vex::velocityUnits::pct);
      FrontLeft.spin(vex::directionType::fwd, ControllerMain.Axis3.position(), vex::velocityUnits::pct);
    }

    if(Axis2){
      //axis 2 controlling right wheels
      BackRight.spin(vex::directionType::rev, ControllerMain.Axis2.position(), vex::velocityUnits::pct);
      FrontRight.spin(vex::directionType::rev, ControllerMain.Axis2.position(), vex::velocityUnits::pct);
    }



    if(ButtonR1){
    //Raises claw up
    Claw1.spin(vex::directionType::fwd);
    Claw2.spin(vex::directionType::fwd);
    }


    else if(ButtonR2){
      //Lowers Claw down
      Claw1.spin(vex::directionType::rev);
      Claw2.spin(vex::directionType::rev);
    }


    else {
      Claw1.stop();
      Claw2.stop();

    }
   

   
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//void graphics( void ){
//  clearScreen(void);
//  drawCircle(100, 100, 50);
//}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}