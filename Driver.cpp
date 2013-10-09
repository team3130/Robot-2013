#include "Driver.h"
DriveSystem::DriveSystem(RobotDrive* chassis){
	speed=1.f;
	precision=0.5f;
	this->drive=chassis;
}
void DriveSystem::update(){
	double speed = 1.0;
	if (left->GetRawButton(1)) speed *= precision;
	if (right->GetRawButton(1))	speed *= precision;
	//feed in [left joystick], [right joystick], [do not square inputs]
	drive->TankDrive(-left->GetY() * speed, -right->GetY() * speed, false);
}
void DriveSystem::bind(Joystick* left, Joystick* right){
	this->left=left;
	this->right=right;
}
void DriveSystem::readFields(){
	
}
void DriveSystem::initFields(){
	
}
