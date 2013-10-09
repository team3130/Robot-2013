/*
 * Engine.h contains all utility functions for Code.
 * TODO:
 * 		SmartDashboard integration/util functions
 * 		
 */
/*
#include "map"
namespace Engine{
	map<double*, string> nfollow;
	void follow(double* ptr, string name){
		nfollow.insert(std::pair<double*, std::string>(ptr, name));
	}
	void updatefollowedn(){
		map<double*, string>::iterator itr;
		for(itr=nfollow.begin();itr!=nfollow.end();itr++){
			*(itr->first)=SmartDashboard::GetNumber(itr->second);
		}
	}
	map<bool*, string> bfollow;
	void follow(bool* ptr, string name){
		bfollow.insert(std::pair<bool*, std::string>(ptr, name));
	}
	void updatefollowedb(){
		map<bool*, string>::iterator itr;
		for(itr=bfollow.begin();itr!=bfollow.end();itr++){
			*(itr->first)=SmartDashboard::GetBoolean(itr->second);
		}
	}
	void update(){
		updatefollowedn();
		updatefollowedb();
	}
}
*/
//Util Functions
double clampf(double val, double low, double high){
	return min(max(val,low),high);
}
