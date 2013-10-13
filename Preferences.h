
namespace Prefs {

	void initializePreferencesValues() {
		Preferences* prefs = Preferences::GetInstance();

		prefs->PutDouble("Winch_Up_Mult", WINCH_UP_MULT); // The multiplier to use when the winch is moving up
		
		prefs->PutDouble("Shooter_OFF", SHOOTER_OFF);
		prefs->PutDouble("Shooter_LOW", SHOOTER_LOW);
		prefs->PutDouble("Shooter_MEDIUM", SHOOTER_MED);
		prefs->PutDouble("Shooter_HIGH", SHOOTER_HIGH);
		
		prefs->PutDouble("Auto_Delay_1", AUTO_DELAY1); // Delay before first disc is shot
		prefs->PutDouble("Auto_Delay_2", AUTO_DELAY2); // Delay before retracting the indexer
		prefs->PutDouble("Auto_Delay_3", AUTO_DELAY3); // Delay before second disc is shot
		prefs->PutDouble("Auto_Delay_4", AUTO_DELAY4); // Delay before retracting the indexer
		prefs->PutDouble("Auto_Delay_5", AUTO_DELAY5); // Delay before third disc is shot
		prefs->PutDouble("Auto_Delay_6", AUTO_DELAY6); // Delay before retracting the indexer
		prefs->PutDouble("Auto_Delay_7", AUTO_DELAY7); // Delay before shooter is turned off
		prefs->PutDouble("Auto_Shooter_Speed", AUTO_SHOOTER_SPEED);
			
		prefs->PutDouble("Precision_Mode_Mult", PRECISIONMODE_MULT);

	}
}