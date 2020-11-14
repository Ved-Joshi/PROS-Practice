#include "main.h"

//Helper Functions
void setIntake(int power){
  intakeLeft = power;
  intakeRight = power;
}

//Driver Control Functions
void setIntakeMotors(){
  //bottom trigger intakes, top trigger outtakes
  int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) -(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
  setIntake(intakePower);
}
