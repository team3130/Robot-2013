#include <math.h>

#ifndef PI
#define PI 3.14159265358979323
#define ML_PI PI
#define TAU 6.28318530718
#define sign(a) (a>0?1:a<0?-1:0)
#endif

class vec3{
public:
	float x,y,z;
	vec3();
	vec3(float x, float y, float z);
	void operator+=(vec3 o);
	void operator-=(vec3 o);
	void operator/=(vec3 o);
	void operator*=(vec3 o);
	void operator/=(float o);
	void operator*=(float o);
	vec3 operator+(vec3 o);
	vec3 operator-(vec3 o);
	vec3 operator/(vec3 o);
	vec3 operator/(float o);
	vec3 operator*(vec3 o);
	vec3 operator*(float o);
	void operator=(vec3 v);
	bool operator==(vec3 v);
	bool operator!=(vec3 v);
	vec3 getsign();
	float length();
	float lengthsq();
	void normalize();
	vec3 normalized();
	bool isbetween(float a, float b, float num);
	bool isbetween(vec3 a, vec3 b, bool issigned);
	bool isnormalized();
	bool sameVector(vec3 v);
	float dot(vec3 v);
	vec3 cross(vec3 v);
	float distancesq(vec3 b);
	float distance(vec3 b);
};
class vec4{
public:
	vec4(){
		x=0;y=0;z=0;w=0;
	}
	vec4(vec3 & v){
		x=v.x;
		y=v.y;
		z=v.z;
		w=0;
	}
	vec4(float xx, float yy, float zz, float ww){x=xx;y=yy;z=zz;w=ww;}
	float x,y,z,w;
	vec3 xyz(){
		return vec3(x,y,z);
	}
	void operator+=(vec3 v){
		x+=v.x;
		y+=v.y;
		z+=v.z;
		w+=1;
	}
};

