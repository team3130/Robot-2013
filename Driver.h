#include "WPILib.h"
class System{
protected:
	System();
	virtual ~System(){ }
public:
	virtual void update() = 0;
	virtual void readFields() = 0;
	virtual void initFields() = 0;
};
class DriveSystem{
protected:
	DriveSystem(RobotDrive* chassis);
public:
	float speed;
	float precision;
private:
	RobotDrive* drive;
	Joystick* left;
	Joystick* right;
public:
	void bind(Joystick* left, Joystick* right);
	void update();
	void readFields();
	void initFields();
};
