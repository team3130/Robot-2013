#ifndef _JOYSTICKAXISBUTTON_H
#define _JOYSTICKAXISBUTTON_H

#include "Wpilib.h"

class JoystickAxisButton : public Trigger
{
public:

	JoystickAxisButton(Joystick* joystick, int axis, float threshold);
	virtual bool Get();

private:
	Joystick*  m_joystick;
	int m_axis;
	float m_threshold;
};


#endif // _JOYSTICKAXISBUTTON_H
