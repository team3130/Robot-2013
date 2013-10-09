#include "WPILib.h"
#include "math.h"
#include "Preferences.h"
#include "Util.h"
#include "Engine.h"
#include "Shooter.h"
#include "Climber.h"
#include "Log.h"
#include "Blinkies.h"

class Errors: public IterativeRobot {
public:
	
	Motor* jags[7]; //left/right drive, shooter motors 1/2,telescopes left/right
	Joystick* sticks[3]; //left, right, gamepad
	Solenoid* sols[7];
	CANJaguar* cans[2];
	Talon* talon;
	
	DigitalInput* tapelimitswitch;

	RobotDrive* drive;
	Compressor* compressor;

	Shooter* shooter;
	Climber* climber;
	Gyro* gyro;
	Timer timer;
	Blinker blinker;
	bool blockingMode;
	
	Errors() {	}

	void RobotInit(){
		
		talon = new Talon(1);		// Winch
		jags[0] = new Motor(2);		// Drive 5
		jags[1] = new Motor(3);		// Drive 4
		jags[2] = new Motor(4);		// Drive 3
		jags[3] = new Motor(5);		// Drive 2
		jags[4] = new Motor(6);		// Tape  6
		jags[5] = new Motor(7);		// Shooter bottom 7
		jags[6] = new Motor(8);		// Shooter top 8
		sols[0] = new Solenoid(7);	// Shooter indexer
		sols[1] = new Solenoid(2);	// Telescopes fwd/back
		sols[2] = new Solenoid(3);	// Telescopes fwd/back
		sols[3] = new Solenoid(6);	// Flipper
		sols[4] = new Solenoid(4);
		sols[5] = new Solenoid(5);
		//cans[0] = new CANJaguar(7);
		//cans[1] = new CANJaguar(8);
		//cans[0]->ChangeControlMode(CANJaguar::kVoltage);
		//cans[1]->ChangeControlMode(CANJaguar::kVoltage);
		
		sols[6] = new Solenoid(1);		// Winch brake
		sticks[0] = new Joystick(1);	// Left Joystick
		sticks[1] = new Joystick(2);	// Right Joystick
		sticks[2] = new Joystick(3);	// Gamepad
		gyro=new Gyro(1);			 	// Gyroscope
		gyro->SetSensitivity(0.007);
		gyro->Reset();
		tapelimitswitch 
		= new DigitalInput(7);

		drive = new RobotDrive(jags[3], jags[2], jags[0], jags[1]);
		shooter = new Shooter(jags[5], jags[6], sols[0], false, false);
		climber = new Climber(talon, jags[4], sols, sticks, tapelimitswitch);

		compressor = new Compressor(5, 2);

		shooter->init();

		drive->SetExpiration(0.5f);
		drive->SetSafetyEnabled(true);
		
#ifdef JAG_CAN
		int i = 6;
		while (i--) {
			jags[i]->ChangeControlMode(CANJaguar::kVoltage);
		}
#endif
		
		timer.Start();
		SmartDashboard::PutBoolean("Blocking?",false);
		conf::init();
	}
	
	void DisabledInit() {
		blinker.write(Disabled);
	}
	/* General init() function. Called in both autonomous and teleop init.
	 * 
	 */
	void init(){
		blockingMode = SmartDashboard::GetBoolean("Blocking?");
		climber->idle_sols=false;
		if(blockingMode){
			sols[1]->Set(true);
			sols[2]->Set(false);
		}else{
			sols[1]->Set(false);
			sols[2]->Set(true);
		}
	}
	void AutonomousInit() {
		init();
		blinker.write(AutoBegin);
		compressor->Start();
		timer.Reset();
	}

	void TeleopInit() {
		init();
		blinker.write(TeleStart);
		climber->setEnabled(true);
		compressor->Start();
	}
	

	void DisabledPeriodic() {
	}

	void AutonomousPeriodic() {
		//cans[0]->Set(0.5);
		
		drive->Drive(0.f, 0.f);

		shooter->setSpeed(AUTO_SHOOTER_SPEED);
		shooter->setEnabled(true);
		double time = timer.Get();
		
		if (time < AUTO_DELAY1) {
			blinker.send(SpinUp);
		} else if (time < AUTO_DELAY2) {
			shooter->setIndexer(true);
		} else if (time < AUTO_DELAY3) {
			shooter->setIndexer(false);
		} else if (time < AUTO_DELAY4) {
			shooter->setIndexer(true);
		} else if (time < AUTO_DELAY5) {
			shooter->setIndexer(false);
		} else if (time < AUTO_DELAY6) {
			shooter->setIndexer(true);
		}
		else if (time < AUTO_DELAY7) {
			shooter->setIndexer(false);
			shooter->setSpeed(AUTO_SHOOTER_SPEED);
		}else{
			blinker.send(SpinDown);
		}
		shooter->update();
		
	}
	
	
	void handleDrive() {
		double speed = 1.0;
		if (sticks[0]->GetRawButton(1))
			speed *= PRECISIONMODE_MULT;
		if (sticks[1]->GetRawButton(1))
			speed *= PRECISIONMODE_MULT;
		drive->TankDrive(-sticks[0]->GetY() * speed,
				-sticks[1]->GetY() * speed, false);
	}
	
	void handleShooter() {
		shooter->setEnabled(true);
		shooter->handleSpeeds(sticks[2]->GetRawButton(3),
				sticks[2]->GetRawButton(1), sticks[2]->GetRawButton(2),
				sticks[2]->GetRawButton(4), false, false);
		shooter->update();
		
		shooter->setIndexer((fabs(shooter->getSpeed()) > 0.0) && 
				sticks[2]->GetRawButton(6));
		sols[3]->Set(sticks[2]->GetRawButton(8));
	}
	
	void TeleopPeriodic() {
		//SmartDashboard::PutNumber("Gyroscope",gyro->GetAngle());
		timer.Reset();
		climber->update();
		handleDrive();
		handleShooter();
		SmartDashboard::PutNumber("Teleop Time", timer.Get());
	}

};

START_ROBOT_CLASS(Errors);
