#include "JoystickAxisTrigger.h"

JoystickAxisTrigger::JoystickAxisTrigger(Joystick* joystick, int axis, float threshold) : m_joystick(joystick),
	m_axis(axis), m_threshold(threshold) {}

bool JoystickAxisTrigger::Get() {
	return m_joystick->GetRawAxis(m_axis) > m_threshold;
}
