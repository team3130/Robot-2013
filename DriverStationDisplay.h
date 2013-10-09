#ifndef DRIVERSTATIONDISPLAY_H
#define DRIVERSTATIONDISPLAY_H

class DriverStationDisplay {
private:
	DriverStationLCD* dslcd;
	const char* enablestring;
	static DriverStationDisplay* m_inst;
	DriverStationDisplay() {
		dslcd = DriverStationLCD::GetInstance();
		enablestring = "****************************";
	}
	
public:
	static DriverStationDisplay* GetInstance() {
		if (m_inst == NULL) {
			m_inst = new DriverStationDisplay;
		}
		return m_inst;
	}
	
	void SetStatus(bool status) {
		static DriverStationLCD* dslcd = DriverStationLCD::GetInstance();
		if (status) {
			dslcd->PrintfLine(DriverStationLCD::kUser_Line1, "%s", enablestring);
			dslcd->PrintfLine(DriverStationLCD::kUser_Line2, "%s", enablestring);
			dslcd->PrintfLine(DriverStationLCD::kUser_Line3, "%s", enablestring);
			dslcd->PrintfLine(DriverStationLCD::kUser_Line4, "%s", enablestring);
			dslcd->PrintfLine(DriverStationLCD::kUser_Line5, "%s", enablestring);
			dslcd->PrintfLine(DriverStationLCD::kUser_Line6, "%s", enablestring);
		} else {
			dslcd->Clear();
		}
		dslcd->UpdateLCD();
	}	
};

#endif //DRIVERSTATIONDISPLAY_H
