#include "JoystickAxisButton.h"

JoystickAxisButton::JoystickAxisButton(Joystick* joystick, int axis, float threshold) : m_joystick(joystick),
	m_axis(axis), m_threshold(threshold) {}

bool JoystickAxisButton::Get() {
	return m_joystick->GetRawAxis(m_axis) > m_threshold;
}
