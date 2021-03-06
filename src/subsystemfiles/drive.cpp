#include "main.h"

pros::ADIGyro gyro('B', 0.91);

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

double avgDriveEncoderValue() {
  return (fabs(driveBackLeft.get_position()) +
         fabs(driveFrontLeft.get_position()) +
         fabs(driveBackRight.get_position()) +
         fabs(driveFrontRight.get_position()))/4;
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
  //define a direction based on units provided
  int direction = abs(units)/units;
  //reset motor encoders and gyro
  resetDriveEncoders();
  gyro.reset();
  //drive forward until units are reached
  while(avgDriveEncoderValue() < abs(units)) {
    setDrive(voltage * direction + gyro.get_value(), voltage * direction - gyro.get_value());
    pros::delay(10);
  }
  //brief brake
  setDrive(-10 * direction, -10 * direction);
  pros::delay(50);
  //set drive back to neutral
  setDrive(0,0);
};

void rotate(int degrees, int voltage) {
  //define our direction, based on the untis provided
  int direction = abs(degrees)/degrees;
  //resetting the gyro
  gyro.reset();
  //turn until units - 5 degrees are reached
  setDrive(-voltage * direction, voltage * direction);
  while(fabs(gyro.get_value()) < abs(degrees * 10) - 50) {
    pros::delay(10);
  }
  //letting the robot lose its momentum
  pros::delay(100);
  //correcting the overshoot or undershoot
  if(fabs(gyro.get_value()) > abs(degrees * 10)) {
    setDrive(0.5 * voltage * direction, 0.5 * -voltage * direction);
    while(fabs(gyro.get_value()) < abs(degrees * 10)) {
      pros::delay(10);
    }
  }
    else if(fabs(gyro.get_value()) < abs(degrees * 10)) {
      setDrive(0.5 * -voltage * direction, 0.5 * voltage * direction);
      while(fabs(gyro.get_value()) < abs(degrees * 10)) {
        pros::delay(10);
      }
    }
  //reset drvie to zero
  setDrive(0, 0);
};
