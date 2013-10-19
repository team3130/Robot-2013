// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


RobotDrive* RobotMap::drivetrainRobotDrive = NULL;
Gyro* RobotMap::drivetrainGyro = NULL;
SpeedController* RobotMap::drivetrainLeftFront = NULL;
SpeedController* RobotMap::drivetrainLeftRear = NULL;
SpeedController* RobotMap::drivetrainRightFront = NULL;
SpeedController* RobotMap::drivetrainRightRear = NULL;
Solenoid* RobotMap::shooterIndexer = NULL;
Solenoid* RobotMap::shooterFlipper = NULL;
SpeedController* RobotMap::shooterTopShooter = NULL;
SpeedController* RobotMap::shooterBottomShooter = NULL;
SpeedController* RobotMap::winchWinch = NULL;
DoubleSolenoid* RobotMap::armsLTelescope = NULL;
DoubleSolenoid* RobotMap::armsRTelescope = NULL;
DigitalInput* RobotMap::tapeTapeLimitSwitch = NULL;
SpeedController* RobotMap::tapeTape = NULL;
Compressor* RobotMap::compressorSystemCompressor = NULL;
DigitalOutput* RobotMap::lightsDigitalOutput1 = NULL;
DigitalOutput* RobotMap::lightsDigitalOutput2 = NULL;
DigitalOutput* RobotMap::lightsDigitalOutput3 = NULL;


void RobotMap::init() {
	drivetrainRobotDrive = new RobotDrive(drivetrainLeftFront, drivetrainRightRear, drivetrainRightFront, drivetrainLeftRear);
	LiveWindow* lw = LiveWindow::GetInstance();
	drivetrainGyro = new Gyro(1, 1);
	lw->AddSensor("Drivetrain", "Gyro", drivetrainGyro);
	drivetrainGyro->SetSensitivity(0.007);
	drivetrainLeftFront = new Jaguar(1, 2);
	lw->AddActuator("Drivetrain", "LeftFront", (Jaguar*) drivetrainLeftFront);
	
	drivetrainLeftRear = new Jaguar(1, 3);
	lw->AddActuator("Drivetrain", "LeftRear", (Jaguar*) drivetrainLeftRear);
	
	drivetrainRightFront = new Jaguar(1, 4);
	lw->AddActuator("Drivetrain", "RightFront", (Jaguar*) drivetrainRightFront);
	
	drivetrainRightRear = new Jaguar(1, 5);
	lw->AddActuator("Drivetrain", "RightRear", (Jaguar*) drivetrainRightRear);
	
	shooterIndexer = new Solenoid(1, 7);
	lw->AddActuator("Shooter", "Indexer", shooterIndexer);
	
	shooterFlipper = new Solenoid(1, 6);
	lw->AddActuator("Shooter", "Flipper", shooterFlipper);
	
	shooterTopShooter = new Jaguar(1, 8);
	lw->AddActuator("Shooter", "TopShooter", (Jaguar*) shooterTopShooter);
	
	shooterBottomShooter = new Jaguar(1, 7);
	lw->AddActuator("Shooter", "BottomShooter", (Jaguar*) shooterBottomShooter);
	
	winchWinch = new Talon(1, 1);
	lw->AddActuator("Winch", "Winch", (Talon*) winchWinch);
	
	armsLTelescope = new DoubleSolenoid(1, 2, 4);      
	
	armsRTelescope = new DoubleSolenoid(1, 3, 5);      
	
	tapeTapeLimitSwitch = new DigitalInput(1, 7);
	lw->AddSensor("Tape", "TapeLimitSwitch", tapeTapeLimitSwitch);
	
	tapeTape = new Jaguar(1, 6);
	lw->AddActuator("Tape", "Tape", (Jaguar*) tapeTape);
	
	compressorSystemCompressor = new Compressor(1, 5, 1, 2);
	
	lightsDigitalOutput1 = new DigitalOutput(1, 1);
	
	lightsDigitalOutput2 = new DigitalOutput(1, 2);
	
	lightsDigitalOutput3 = new DigitalOutput(1, 3);
	
	lightsDigitalOutput4 = new DigitalOutput(1, 4);

}
