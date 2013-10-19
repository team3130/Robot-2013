#ifndef _JOYSTICKAXISTRIGGER_H
#define _JOYSTICKAXISTRIGGER_H

#include "Wpilib.h"

class JoystickAxisTrigger : public Trigger
{
public:

	JoystickAxisTrigger(Joystick* joystick, int axis, float threshold);
	virtual bool Get();

private:
	Joystick*  m_joystick;
	int m_axis;
	float m_threshold;
};


#endif // _JOYSTICKAXISTRIGGER_H
