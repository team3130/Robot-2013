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
	
namespace conf{

	float getShooterSpeed(char* descriptor){
		if(descriptor=="low"||descriptor=="LOW")return SmartDashboard::GetNumber("Shooter Low");
		if(descriptor=="med"||descriptor=="MED")return SmartDashboard::GetNumber("Shooter Med");
		if(descriptor=="high"||descriptor=="HIGH")return SmartDashboard::GetNumber("Shooter High");
		if(descriptor=="off"||descriptor=="OFF")return SmartDashboard::GetNumber("Shooter Off");
		printf("WARNING: ");
		printf("invalid input to getShooterSpeed [%s]\n",descriptor);
		return 0;
	}
	float getSpeed(){
		return SmartDashboard::GetNumber("Robot Speed");
	}
	float getPrecSpeed(){
		return SmartDashboard::GetNumber("Precision Speed");
	}
	void init(){
		SmartDashboard::PutNumber("Shooter Low", 4.5);
		SmartDashboard::PutNumber("Shooter Med", 6.0);
		SmartDashboard::PutNumber("Shooter High", 9.5);
		SmartDashboard::PutNumber("Shooter Off", -0.5);
		SmartDashboard::PutNumber("Robot Speed", 1.0);
		SmartDashboard::PutNumber("Precision Speed", 0.2);
	}
	
	float distf(float a, float b){
		printf("<%2.2f>\n", fabs(a-b));
		return fabs(a-b);
	}
	
	
	#define WINCH_UP_MULT 0.4 // The multiplier to use when the winch is moving up
	
		
	#define AUTO_DELAY1 7.0 // Delay before first disc is shot
	#define AUTO_DELAY2 7.5 // Delay before retracting the indexer
	#define AUTO_DELAY3 9.0 // Delay before second disc is shot
	#define AUTO_DELAY4 9.5 // Delay before retracting the indexer
	#define AUTO_DELAY5 11.0 // Delay before third disc is shot
	#define AUTO_DELAY6 11.5 // Delay before retracting the indexer
	#define AUTO_DELAY7 14.0 // Delay before shooter is turned off
	#define AUTO_SHOOTER_SPEED 	(9.5)
		
	#define PRECISIONMODE_MULT 0.5
};
#endif //CONFIG_H
