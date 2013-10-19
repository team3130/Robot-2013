// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Lights.h"
#include "../Robotmap.h"
#include "../Commands/LightsDisabled.h"
Lights::Lights() : Subsystem("Lights") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	digitalOutput1 = RobotMap::lightsDigitalOutput1;
	digitalOutput2 = RobotMap::lightsDigitalOutput2;
	digitalOutput3 = RobotMap::lightsDigitalOutput3;
	digitalOutput4 = RobotMap::lightsDigitalOutput4;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Lights::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new LightsDisabled());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lights::SetMode(Mode mode) {
	unsigned int val = (unsigned int)mode;
	bool b1 = val%2;
	bool b2 = (val/2)%2;
	bool b3 = (val/4)%2;
	digitalOutput1->Set(b1);
	digitalOutput2->Set(b2);
	digitalOutput3->Set(b3);
}
