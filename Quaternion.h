#pragma once
#include "Vector.h"
class Quaternion {
private: 
	double w, x, y, z;
public: 
	Quaternion(double w, double x, double y, double z);
	Quaternion(double w, Vector vec);

	//Methods

	//Operators
	inline Quaternion operator*(const Quaternion& other) const {
		return Quaternion(this->w*other.w - this->x*other.x - this->y*other.y - this->z*other.z, this->w*other.x+this->x*other.w+this->y*other.z-this->z*other.y, this->w*other.y+this->x*other.z+this->y*other.w-this->z*other.x, this->w*other.z+this->x*other.y-this->y*other.x+this->z*other.w);
	}

	//Get Methods
	inline double getW() {
		return this->w;
	}
	inline double getX() {
		return this->x;
	}
	inline double getY() {
		return this->y;
	}
	inline double getZ() {
		return this->z;
	}
};