#include "WPILib.h"
class Errors: public IterativeRobot{
public:
	Errors() : left(1), right(2), j(3){
		
	}
	Jaguar j;
	//RobotDrive drive;
	Joystick left;
	Joystick right;
	void RobotInit(){
		
	}
	void DisabledInit(){
	}
	void AutonomousInit(){
	}
	void TeleopInit(){
	}
	void DisabledPeriodic(){
	}
	void AutonomousPeriodic(){
		j.Set(-0.5f);
	}
	void TeleopPeriodic(){
		j.Set(0.5f);
		//drive.TankDrive(left,right);
	}
};

START_ROBOT_CLASS(Errors);
