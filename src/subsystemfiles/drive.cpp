#include "main.h"

//Helper Functions

void setDrive(int left, int right) {
  driveBackLeft = left;
  driveFrontLeft = left;
  driveBackRight = right;
  driveFrontRight = right;
}

void resetDriveEncoders() {
  driveBackLeft.tare_position();
  driveBackRight.tare_position();
  driveFrontLeft.tare_position();
  driveFrontRight.tare_position();
}

//Driver Control Functions

void setDriveMotors() {
  int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  if(abs(leftJoystick < 10)){
    leftJoystick = 0;
  }
  if(abs(rightJoystick < 10)){
    rightJoystick = 0;
  }
  setDrive(leftJoystick, rightJoystick);
}

//AUTON FUNCTIONS

void translate(int units, int voltage) {
  //reset motor encoders
  resetEncoders();
  //drive forward until units are reached

  //brief brake

  //set drive back to neutral
};
