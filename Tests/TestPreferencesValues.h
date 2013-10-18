#ifndef _TESTPREFERENCESVALUES_H
#define _TESTPREFERENCESVALUES_H

#include "Test.h"
#include "../Robot.h"

class TestPreferencesValues : public Test {
public:
	explicit TestPreferencesValues() : Test("Test Preferences Values") {
	}
	void Run() {
		try {
			double x = Robot::prefs->GetDouble("Shooter_Off");
			x = Robot::prefs->GetDouble("Shooter_Low");
			x = Robot::prefs->GetDouble("Shooter_Med");
			x = Robot::prefs->GetDouble("Shooter_High");
		} catch (Error* e) {
			Message = (char*)e->GetMessage();
			status = Fail;
		}
	}	
};

#endif // _TESTPREFERENCESVALUES_H
