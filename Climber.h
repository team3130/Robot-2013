#ifndef CLIMBER_H
#define CLIMBER_H

#include "Config.h"

#ifdef LIMIT_DRIVERSTATION
//#include "DriverStationDisplay.h"
#endif

class Climber { 
	
public:
	Motor* tape;		//tape
	Talon* winch;		//winch
	Solenoid** sols;	//array of solenoids
	Joystick** sticks;	//left/right/gamepad
	double wspeed;		//speed is current motor speed. Domain = [-1.0,1.0]
	double tspeed;		//-1 is defined as going DOWN. 1 is UP.
	bool enabled;		//Winch and tape only move if this flag is set.
	bool idle_sols;
	bool last_pressed;
	bool winch_enabled;
	bool last_winch_pressed;
	DigitalInput* dio;
	
public:
	
	Climber(Talon* winch_, Motor* tape_, Solenoid** sols_, Joystick** sticks_, DigitalInput* limit) {
		winch = winch_;
		tape = tape_;
		wspeed = 0.0;
		tspeed = 0.0;
		enabled = false;
		sols = sols_;
		sticks = sticks_;
		idle_sols = false;
		last_pressed = false;
		winch_enabled = true;
		last_winch_pressed = false;

		dio = limit;
		
		// Sets the arm solenoids to the UP position
		sols[1]->Set(false);
		sols[2]->Set(true);
	}

private:
	void SetStatus(bool status) {
		//static DriverStationLCD* dslcd = DriverStationLCD::GetInstance();
		static char* enablestring = "###############################################";
									
		if (status) {
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line1, "%s", enablestring);
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line2, "%s", enablestring);
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line3, "%s", enablestring);
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line4, "%s", enablestring);
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line5, "%s", enablestring);
			DriverStationLCD::GetInstance()->PrintfLine(DriverStationLCD::kUser_Line6, "%s", enablestring);
		} else {
			DriverStationLCD::GetInstance()->Clear();
		}
		DriverStationLCD::GetInstance()->UpdateLCD();
	}
public:
	void setMotors(Motor* t, Talon* w){
		CONSOLE("w motor\t\t");
		winch = w;
		CONSOLE("t motor\t\t");
		tape = t;
	}
	void enable(){
		enabled = true;
	}
	void disable(){
		CONSOLE("comp dis\t\t");
		enabled = false;
	}
	void setEnabled(bool in){
		CONSOLE("comp en\t\t");
		enabled = in;
	}
	bool isEnabled(){
		return enabled;
	}
	double getWinchSpeed(){
		return wspeed;
	}
	double getTelSpeed(){
		return tspeed;
	}
public:
	/*
	 * Set winch/tape speeds; arm solenoids; winch brake; tape limit switch indicator.
	 */
	void update(){
		// Tape Home Indicator
		CONSOLE("tape check\t\t");
		
		#ifdef JAG_CAN
				bool tapeStatus = (!(tape->GetReverseLimitOK()&&tape->GetForwardLimitOK()));
		#endif
		#ifdef JAG_PWM
				bool tapeStatus = (dio->Get());
		#endif
				SetStatus(tapeStatus);
				SmartDashboard::PutBoolean("Tape Home", tapeStatus);
		//deadzones for winch joystick.
		wspeed = util::deadzones(-sticks[2]->GetY(), 0.1);
		if(wspeed > 0){
			wspeed *= WINCH_UP_MULT;
		}
		//get tape speed.
		tspeed = util::deadzones(sticks[2]->GetRawAxis(5), 0.1);
		if(tapeStatus)tspeed=min(tspeed,0);
		// only set tape/winch speed if enabled == true.
		// otherwise, set both to 0.
		
		//when true, make maximum 0
		if(enabled){
			winch->Set(wspeed);
			tape->Set(tspeed);
		}else { winch->Set(0); tape->Set(0);}
		CONSOLE("get buttons\t\t");
		if (sticks[2]->GetRawButton(5)) {
			sols[1]->Set(false);
			sols[2]->Set(true);
		}
		if (sticks[2]->GetZ()> 0.1f) {
			sols[1]->Set(true);
			sols[2]->Set(false);
		}
		
		// Idle Solenoids Toggle
		if(sticks[2]->GetRawButton(10)>last_pressed){
			idle_sols=!idle_sols;
		}
		last_pressed = sticks[2]->GetRawButton(10);
		sols[4]->Set(!idle_sols);
		sols[5]->Set(idle_sols);
		


		// Winch Brake
		if(sticks[2]->GetRawButton(9) > last_winch_pressed){
			winch_enabled=!winch_enabled;
		}
		last_winch_pressed = sticks[2]->GetRawButton(9);
		sols[6]->Set(winch_enabled);
	}
};

#endif // CLIMBER_H
