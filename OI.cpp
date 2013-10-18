// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ArmsBackward.h"
#include "Commands/ArmsForward.h"
#include "Commands/ArmsNeutral.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DisableCompressor.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/EnableCompressor.h"
#include "Commands/Flip.h"
#include "Commands/LightsAutoBegin.h"
#include "Commands/LightsBlue.h"
#include "Commands/LightsDisabled.h"
#include "Commands/LightsFire.h"
#include "Commands/LightsRed.h"
#include "Commands/LightsSpinDown.h"
#include "Commands/LightsSpinUp.h"
#include "Commands/LightsTeleStart.h"
#include "Commands/MoveTape.h"
#include "Commands/MoveWinch.h"
#include "Commands/PrecisionMode.h"
#include "Commands/RunTests.h"
#include "Commands/Shoot.h"
#include "Commands/SpeedAuto.h"
#include "Commands/SpeedHigh.h"
#include "Commands/SpeedLow.h"
#include "Commands/SpeedMed.h"
#include "Commands/SpeedOff.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	gamepad = new Joystick(3);
	
	select = new JoystickButton(gamepad, 8);
	select->WhileHeld(new Flip());
	rShoulder = new JoystickButton(gamepad, 6);
	rShoulder->WhenPressed(new Shoot());
	y = new JoystickButton(gamepad, 4);
	y->WhenPressed(new SpeedLow());
	x = new JoystickButton(gamepad, 3);
	x->WhenPressed(new SpeedLow());
	b = new JoystickButton(gamepad, 2);
	b->WhenPressed(new SpeedLow());
	a = new JoystickButton(gamepad, 1);
	a->WhenPressed(new SpeedLow());
	rightJoystick = new Joystick(2);
	
	rTrigger = new JoystickButton(rightJoystick, 1);
	rTrigger->WhileHeld(new PrecisionMode());
	leftJoystick = new Joystick(1);
	
	lTrigger = new JoystickButton(leftJoystick, 1);
	lTrigger->WhileHeld(new PrecisionMode());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("Flip", new Flip());
	SmartDashboard::PutData("Shoot", new Shoot());
	SmartDashboard::PutData("Speed Off", new SpeedOff());
	SmartDashboard::PutData("Speed Low", new SpeedLow());
	SmartDashboard::PutData("Speed Med", new SpeedMed());
	SmartDashboard::PutData("Speed High", new SpeedHigh());
	SmartDashboard::PutData("Speed Auto", new SpeedAuto());
	SmartDashboard::PutData("Arms Forward", new ArmsForward());
	SmartDashboard::PutData("Arms Backward", new ArmsBackward());
	SmartDashboard::PutData("Arms Neutral", new ArmsNeutral());
	SmartDashboard::PutData("Precision Mode", new PrecisionMode());
	SmartDashboard::PutData("Enable Compressor", new EnableCompressor());
	SmartDashboard::PutData("Disable Compressor", new DisableCompressor());
	SmartDashboard::PutData("Lights Disabled", new LightsDisabled());
	SmartDashboard::PutData("Lights Auto Begin", new LightsAutoBegin());
	SmartDashboard::PutData("Lights Tele Start", new LightsTeleStart());
	SmartDashboard::PutData("Lights Spin Up", new LightsSpinUp());
	SmartDashboard::PutData("Lights Spin Down", new LightsSpinDown());
	SmartDashboard::PutData("Lights Fire", new LightsFire());
	SmartDashboard::PutData("Lights Red", new LightsRed());
	SmartDashboard::PutData("Lights Blue", new LightsBlue());
	SmartDashboard::PutData("Run Tests", new RunTests());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getGamepad() {
	return gamepad;
}
Joystick* OI::getRightJoystick() {
	return rightJoystick;
}
Joystick* OI::getLeftJoystick() {
	return leftJoystick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS