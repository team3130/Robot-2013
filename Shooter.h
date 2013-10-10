#ifndef SHOOTER_H
#define SHOOTER_H

#include <math.h>
#include "Log.h"
#include "Config.h"

double clampf(double val, double low, double high);

class Shooter {
public:

	Shooter(Motor* l, Motor* r, Solenoid* s, bool invleft, bool invright) {
		lmult = invleft ? -1 : 1;
		rmult = invright ? -1 : 1;
		enabled = false;
		left = l;
		right = r;
		speed = 0.0;
		indexer = s;
		voltagecontrol = true;
	}

private:
	double speed;
	Motor* left;
	Motor* right;
	double lmult;
	double rmult;
	bool enabled;
	Solenoid* indexer;
	bool voltagecontrol;
public:
	void enable() {
		enabled = true;
	}
	void setVoltageControl(bool in) {
		voltagecontrol = in;
	}
	bool isVoltageControl() {
		return voltagecontrol;
	}
	void disable() {
		enabled = false;
	}
	void setEnabled(bool in) {
		CONSOLE("s:setEn\t\t");
		enabled = in;
	}
	bool isEnabled() {
		return enabled;
	}
	void setMotors(Motor* l, Motor* r) {
		left = l;
		right = r;
	}
	void setSpeed(double s) {
		speed = s;
	}
	void setIndexer(bool extended) {
		CONSOLE("setting...\t\t");
		indexer->Set(extended);
		CONSOLE("done.\t\t");
	}
	double getSpeed() {
		return speed;
	}
	double getLeftSpeed() {
		return speed * lmult;
	}
	double getRightSpeed() {
		return speed * rmult;
	}
	void setInversions(bool leftInv, bool rightInv) {
		if (leftInv)
			lmult = -fabs(lmult);
		if (rightInv)
			rmult = -fabs(rmult);
	}
	void update() {
		float temp = speed;
		if (voltagecontrol)
			temp /= PWM_VOLT;
		left->Set(temp);
		right->Set(temp);
	}
	void init() {
		enable();
	}
	double handleSpeeds(bool X, bool A, bool B, bool Y, bool LT, bool RT) {
		static bool lastA = false;
		static bool lastB = false;
		static bool lastX = false;
		static bool lastY = false;
		if (A > lastA) {
			if (speed < 0)
				speed = 0;
			else
				speed = SHOOTER_OFF;
		}
		if (B > lastB) {
			speed = SHOOTER_LOW;
		}
		if (X > lastX) {
			if (speed > 0)
				speed = 0;
			else
				speed = SHOOTER_MED;
		}
		if (Y > lastY) {
			if (speed > 0)
				speed = 0;
			else
				speed = SHOOTER_HIGH;
		}
		lastA = A;
		lastB = B;
		lastX = X;
		lastY = Y;
		return speed;
	}
};

#endif // SHOOTER_H
