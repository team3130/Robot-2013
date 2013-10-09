#include <math.h>
#include "Geom.h"
	vec3::vec3(){
		x=0;y=0;z=0;
	}
	vec3::vec3(float xx, float yy, float zz){x=xx;y=yy;z=zz;}
	void vec3::operator+=(vec3 v){
		x+=v.x;
		y+=v.y;
		z+=v.z;
	}
	void vec3::operator-=(vec3 v){
		x+=-v.x;
		y+=-v.y;
		z+=-v.z;
	}
	void vec3::operator*=(float v){
		x*=v;
		y*=v;
		z*=v;
	}
	void vec3::operator/=(float v){
		x/=v;
		y/=v;
		z/=v;
	}
	vec3 vec3::operator+(vec3 v){
		return vec3(x+v.x,y+v.y,z+v.z);
	}
	vec3 vec3::operator-(vec3 v){
		return vec3(x-v.x,y-v.y,z-v.z);
	}
	vec3 vec3::operator*(float v){
		return vec3(x*v,y*v,z*v);
	}
	void vec3::operator*=(vec3 v){
		x*=v.x;
		y*=v.y;
		z*=v.z;
	}
	void vec3::operator/=(vec3 v){
		x/=v.x;
		y/=v.y;
		z/=v.z;
	}
	vec3 vec3::operator/(float v){
		return vec3(x/v,y/v,z/v);
	}
	vec3 vec3::operator/(vec3 v){
		return vec3(x/v.x,y/v.y,z/v.z);
	}
	void vec3::operator=(vec3 v){
		x=v.x;
		y=v.y;
		z=v.z;
	}
	bool vec3::operator==(vec3 v){
		return (x==v.x&&y==v.y&&z==v.z);
	}
	bool vec3::operator!=(vec3 v){
		return (x!=v.x||y!=v.y||z!=v.z);
	}
	vec3 vec3::getsign(){
		return vec3(sign(x),sign(y),sign(z));
	}
	float vec3::length(){
		return sqrt((x*x)+(y*y)+(z*z));
	}
	float vec3::lengthsq(){
		return ((x*x)+(y*y)+(z*z));
	}
	void vec3::normalize(){
		float l=length();
		x/=l;y/=l;z/=l;
	}
	vec3 vec3::normalized(){
		vec3 n(x,y,z);
		n.normalize();
		return n;
	}
	bool vec3::isbetween(float a, float b, float num){
		return (num>=a&&num<=b)||(num>=b&&num<=a);
	}
	bool vec3::isbetween(vec3 a, vec3 b, bool issigned=false){
		return	isbetween(a.x,b.x,x)&&isbetween(a.y,b.y,y)&&isbetween(a.z,b.z,z);
	}
	bool vec3::isnormalized(){
		return (lengthsq()==1);
	}
	bool vec3::sameVector(vec3 v){
		vec3 self(x,y,z);
		float lensq=lengthsq();
		float vlensq=v.lengthsq();
		v/=vlensq;
		self/=lensq;
		if(v==self)return true;
		else return false;
	}
	float vec3::dot(vec3 v){
		return (x*v.x) + (y*v.y) + (z*v.z);
	}
	vec3 vec3::cross(vec3 v){
		float x=(y*v.z) - (z*v.y);
		float y=(z*v.x) - (x*v.z);
		float z=(x*v.y) - (y*v.x);
		return vec3(x,y,z);
	}
	float vec3::distancesq(vec3 b){
		return pow((x-b.x),2)+pow((y-b.y),2)+pow((z-b.z),2);
	}
	float vec3::distance(vec3 b){
		return sqrt(distancesq(b));
	}
