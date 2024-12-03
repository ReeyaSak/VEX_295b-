#include "vex.h"


using namespace vex;
brain Brain;


// A global instance of competition
competition Competition;
controller Controller1 = controller();
//left motors
motor leftMotorA = motor (PORT8, false);
motor leftMotorB = motor (PORT6, false);
motor leftMotorC = motor (PORT12, false);
motor_group leftMotors = motor_group (leftMotorA, leftMotorB, leftMotorC);
//right motors
motor rightMotorA = motor (PORT20, true);
motor rightMotorB = motor (PORT15, true);
motor rightMotorC = motor (PORT3, true);
motor_group rightMotors = motor_group (rightMotorA, rightMotorB, rightMotorC);
inertial Inertial = inertial (PORT1);


digital_out dig1 = digital_out(Brain.ThreeWirePort.A);


motor intakeMotor = motor (PORT13, true);
//define your global instances of motors snd oher devices here
drivetrain Drivetrain = drivetrain (leftMotors, rightMotors,3,361.95,5,mm,1);






// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


//void pre_auton(void) {


  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...




/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/



// The autononomous code is written here
void autonomous(void) {
  Brain.Screen.printAt( 10, 50, "Controller1.ButtonA.pressing();" );


  Drivetrain.setDriveVelocity(30, pct);


  Drivetrain.setTurnVelocity(30, pct);
 
  Drivetrain.driveFor(fwd, 18 , inches);
  wait(20,msec);
 
  dig1.set(true);


  intakeMotor.spin(fwd, 650, rpm);


  Drivetrain.turnFor(left, 90, degrees);


  wait(20,msec);
 
  Drivetrain.driveFor(reverse, 24, inches);


  Drivetrain.turnFor(right, 90, degrees);


  Drivetrain.driveFor(reverse, 24, inches);


  Drivetrain.turnFor(right, 135, degrees);


  Drivetrain.driveFor(fwd, 24, inches);


  dig1.set(false);


  Drivetrain.turnFor(right, 180, degrees);


  Drivetrain.driveFor(fwd, 40, inches);




  //Smartdrive.driveFor(fwd, 24, inches);


 }





//
// Main will set up the competition functions and callbacks.
//
int main() {
  autonomous();
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  //Competition.drivercontrol(usercontrol);


  // Run the pre-autonomous function.
  //pre_auton();


  // Prevent main from exiting with an infinite loop.
  //while (true) {
   // wait(100, msec);
  }


