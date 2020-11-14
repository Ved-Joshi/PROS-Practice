#include "main.h"

//Helper Functions
void setLift(int power){
  lift = power;
}

//Driver Control Functions
void setLiftMotor(){
  //bottom trigger intakes, top trigger outtakes
  int liftPower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) -(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
  setLift(liftPower);
}
