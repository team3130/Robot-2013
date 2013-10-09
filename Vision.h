#include "Geom.h"
class Vision{
private:
	vec3 camera;
	vec3 target;
	vec3 tbounds[4];
	float dist;
	float angle;
	NetworkTable* visionTable;
private:
	float get(string key){
		return visionTable->GetNumber(key);
	}
public:
	Vision(){
		visionTable = NetworkTable::GetTable("Vision");
		NetworkTable* sdash = NetworkTable::GetTable("SmartDashboard");
		if(!sdash->ContainsKey("bot_height"))	SmartDashboard::PutNumber("bot_height",0);
		if(!sdash->ContainsKey("target_height"))SmartDashboard::PutNumber("target_height",0);
		if(!sdash->ContainsKey("cam_angle"))	SmartDashboard::PutNumber("cam_angle",0);
	}
	/*
	 * Return the rotation vector the robot needs to turn by to face the target.
	 * Does not account for distance to the target. +Y rotation indicates a right
	 * turn. Presumably, both x and z rotations should be 0.
	 */
	vec3 aim(){
		return vec3();
	}
	/*
	 * Return the shooter voltage required to shoot at the target. 
	 * Does not account for rotation to the target.
	 */
	float getVoltageRequired(){
		//TODO: insert voltage modeling function here.
	}
	/*
	 * Queries SmartDashboard fields for target data - distance, 
	 * target endpoinds, and angle. Returns false if vision is
	 * not initialized in RoboRealm.
	 */
	bool queryImageData(bool sendData = true){
		
		visionTable->PutNumber("bot_height",SmartDashboard::GetNumber("bot_height"));
		visionTable->PutNumber("target_height",SmartDashboard::GetNumber("target_height"));
		visionTable->PutNumber("cam_angle",SmartDashboard::GetNumber("cam_angle"));
		
		if(!visionTable->ContainsKey("Vision_Init"))return false;
		dist  = visionTable->GetNumber("distance");
		angle = visionTable->GetNumber("angle");
		
		return true;
	}
	/*
	 * Set to the center of the vision target, respective to the camera.
	 * Eg. if the target is directly in front of, but slightly higher
	 * than the target, then target may equal (0,5,-10). Negative z values
	 * go FORWARDS. Positive z values go BACKWARDS.
	 */
	void setTarget(vec3 t){
		target=t;
	}
	vec3 getTarget(){
		return target;
	}
	/*
	 * Set the location of the camera; generally, set this to (0,0,0);
	 * The target is essentially subtracted by the camera's location.
	 */
	void setCamera(vec3 c){
		camera=c;
	}
	
};
