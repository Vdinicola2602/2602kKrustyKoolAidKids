#include "vex.h"

using namespace vex;

 /* ---- START VEXCODE CONFIGURED DEVICES ---- */
 /* Robot Configuration:                       */ 
 /* [Name]               [Type]        [Port(s)] */
 /* ---- END VEXCODE CONFIGURED DEVICES ---- */
 /*----------------------------------------------------------------------------*/
 /*                                                                            */
 /*    Module:       main.cpp                                                  */
 /*    Author:       C:\Users\first                                            */
 /*    Created:      Wed Sep 18 2019                                           */
 /*    Description:  V5 project                                                */
 /*                                                                            */
 /*----------------------------------------------------------------------------*/


// A global instance of vex::brain used for printing to the V5 brain screen
 vex::brain       Brain;
 // A global instance of vex::competition
 vex::competition Competition;

 //define your global instances of motors and other devices here
 //Port Values for driving motors & Controller
 vex::motor BackRight      = vex::motor( vex::PORT3);
 vex::motor FrontRight     = vex::motor(vex::PORT4);
 vex::motor FrontLeft      = vex::motor(vex::PORT1); 
 vex::motor BackLeft       = vex::motor(vex::PORT2);
 vex::controller ControllerMain = vex::controller();
 vex::motor Claw          = vex::motor(vex::PORT5);
 vex::motor Lift1          = vex::motor(PORT20);
 vex::motor Lift2          = vex::motor(PORT11); 
 /*---------------------------------------------------------------------------*/
 /*                          Pre-Autonomous Functions                         */
 /*                                                                           */
 /*  You may want to perform some actions before the competition starts.      */
 /*  Do them in the following function.  You must return from this function   */
 /*  or the autonomous and usercontrol tasks will not be started.  This       */
 /*  function is only called once after the cortex has been powered on and    */ 
 /*  not every time that the ro cbot is disabled.                               */
 /*---------------------------------------------------------------------------*/
 
 void pre_auton( void ) {

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
   /* ..........................................................................*/
   /* Insert autonomous user code here.                                         */
   /* .......................................................................... */
 Brain.Screen.print("Autobot Activated");
   
 
  // Code Starts here:
  // Moves forward for a block
 
   BackLeft.spinFor( 100, vex::rotationUnits::deg);
   FrontLeft.spinFor( 100, vex::rotationUnits::deg);
   BackRight.spinFor( -100, vex::rotationUnits::deg);
   FrontRight.spinFor( -100, vex::rotationUnits::deg);

   vex::task::sleep(5);

   FrontLeft.spinFor( 100, vex::rotationUnits::deg);
   BackLeft.spinFor(100, vex::rotationUnits::deg);

   vex::task::sleep(5);
  
   Claw.spinToPosition(-150, vex::rotationUnits::deg);

   vex::task::sleep(2);

   Claw.spinToPosition(-70, vex::rotationUnits::deg);
   
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
 //User control code here, inside the loop
   Brain.Screen.print("Driving Mode Activated");

   while (1) {
     /* This is the main execution loop for the user control program. */
     /* Each time through the loop your program should update motor + servo */ 
     /* values based on feedback from the joysticks. */
     /*     ........................................................................ */
     /* Insert user code here. This is where you use the joystick values to */
     /* update your motors, etc.*/
     /* ........................................................................ */
     if(Axis3){
       
       // Axis 3 controlleing left wheels
       BackLeft.spin(vex::directionType::fwd, ControllerMain.Axis3.position(), vex::velocityUnits::pct);
       FrontLeft.spin(vex::directionType::fwd, ControllerMain.Axis3.position(), vex::velocityUnits::pct);
     }
 
     if(Axis2){
      //  axis 2 controlling right wheels
       BackRight.spin(vex::directionType::rev, ControllerMain.Axis2.position(), vex::velocityUnits::pct);
       FrontRight.spin(vex::directionType::rev, ControllerMain.Axis2.position(), vex::velocityUnits::pct);
     }
 
 
     // Stuff for Claw down below
 
 
 
    // This code controlls the lift mechanics of the claw
     if(ControllerMain.ButtonR1.pressing()){
    // Raises claw up
     Lift1.spin(vex::directionType::fwd, 50, vex::velocityUnits::rpm);
     Lift2.spin(vex::directionType::rev, 50, vex::velocityUnits::rpm);
     }
 
 
     else if(ControllerMain.ButtonR2.pressing()){
      // Lowers Claw down
       Lift1.spin(vex::directionType::rev, 50, vex::velocityUnits::rpm);
       Lift2.spin(vex::directionType::fwd, 50, vex::velocityUnits::rpm);
     }
 
 
    else {
       Lift1.stop();
       Lift2.stop();
    }    
 
     
    
 
    // This code opens up the claw
    if(ControllerMain.ButtonA.pressing()){
      // Opens claw:
       Claw.spinToPosition(-200, vex::rotationUnits::deg);
    }
 
     else if(ControllerMain.ButtonB.pressing()){
      Claw.spinToPosition( -15, vex::rotationUnits::deg);
    }

    else {
      Claw.stop();
    }
    
     vex::task::sleep(20);// Sleep the task for a short amount of time to prevent wasted resources. 
   } 
 }
 
 
  // Main will set up the competition functions and callbacks.
 
 int main() {
     // Set up callbacks for autonomous and driver control periods.
     Competition.autonomous( autonomous );
     Competition.drivercontrol( usercontrol );
     
    //  Run the pre-autonomous function. 
     pre_auton();
        
    // Prevent main from exiting with an infinite loop.                        
     while(1) {
       vex::task::sleep(100);// Sleep the task for a short amount of time to prevent wasted resources.
       }    
 }