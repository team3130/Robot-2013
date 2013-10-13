#ifndef CONFIG_H
#define CONFIG_H

//#define JAG_CAN 	// Use CAN for Jaguars
#define JAG_PWM 	// Use PWM for Jaguars

#ifdef JAG_PWM
	#define PWM_VOLT (DriverStation::GetInstance()->GetBatteryVoltage() - 1.0) // The voltage used as a reference for PWM
	typedef Jaguar Motor;
#endif
#ifdef JAG_CAN
	#define PWM_VOLT 1.0 // Disable voltage dividers: using voltage control
	typedef CANJaguar Motor;
#endif
#define CONSOLE(msg) //printf(msg)
	

	
	#define WINCH_UP_MULT 0.4 // The multiplier to use when the winch is moving up
		
	#define SHOOTER_OFF -0.5
	#define SHOOTER_lOW 4.0
	#define SHOOTER_MED 6.0
	#define SHOOTER_HIGH 9.5
	
	#define AUTO_DELAY1 7.0 // Delay before first disc is shot
	#define AUTO_DELAY2 7.5 // Delay before retracting the indexer
	#define AUTO_DELAY3 9.0 // Delay before second disc is shot
	#define AUTO_DELAY4 9.5 // Delay before retracting the indexer
	#define AUTO_DELAY5 11.0 // Delay before third disc is shot
	#define AUTO_DELAY6 11.5 // Delay before retracting the indexer
	#define AUTO_DELAY7 14.0 // Delay before shooter is turned off
	#define AUTO_SHOOTER_SPEED 	(9.5/PWM_VOLT)
		
	#define PRECISIONMODE_MULT 0.5
	
#endif

#ifdef prefs_config
	
static Preferences* prefs = Preferences::GetInstance();	
	
	#define WINCH_UP_MULT prefs->GetDouble("Winch_Up_Mult") // The multiplier to use when the winch is moving up
		
	#define SHOOTER_OFF prefs->GetDouble("Shooter_OFF")
	#define SHOOTER_LOW prefs->GetDouble("Shooter_LOW")
	#define SHOOTER_MED prefs->GetDouble("Shooter_MEDIUM")
	#define SHOOTER_HIGH prefs->GetDouble("Shooter_HIGH")
	
	#define AUTO_DELAY1 prefs->GetDouble("Auto_Delay_1") // Delay before first disc is shot
	#define AUTO_DELAY2 prefs->GetDouble("Auto_Delay_2") // Delay before retracting the indexer
	#define AUTO_DELAY3 prefs->GetDouble("Auto_Delay_3") // Delay before second disc is shot
	#define AUTO_DELAY4 prefs->GetDouble("Auto_Delay_4") // Delay before retracting the indexer
	#define AUTO_DELAY5 prefs->GetDouble("Auto_Delay_5") // Delay before third disc is shot
	#define AUTO_DELAY6 prefs->GetDouble("Auto_Delay_6") // Delay before retracting the indexer
	#define AUTO_DELAY7 prefs->GetDouble("Auto_Delay_7") // Delay before shooter is turned off
	#define AUTO_SHOOTER_SPEED 	prefs->GetDouble("Auto_Shooter_Speed")
		
	#define PRECISIONMODE_MULT prefs->GetDouble("Precision_Mode_Mult")
	
#endif
	
#endif //CONFIG_H
