#pragma once
#include "Point3D.h"
class Vector {
private: 
	double x, y, z;

public: 
	Vector(double Vx, double Vy, double Vz) {
		this->x = Vx;
		this->y = Vy;
		this->z = Vz;
	};
	Vector(Point3D start, Point3D end) {
		Point3D asPoint = end - start;
		x = asPoint.getX();
		y = asPoint.getY();
		z = asPoint.getZ();
	};
	Vector(Point3D fromPoint) {
		this->x = fromPoint.getX();
		this->y = fromPoint.getY();
		this->z = fromPoint.getZ();
	}

	//Operators
	inline Vector operator+(const Vector& other) const {
		return Vector(asPoint() + other.asPoint());
	}
	inline Vector operator-(const Vector& other) const {
		return Vector(asPoint() - other.asPoint());
	}
	inline Vector operator*(const int& scalar) const {
		return Vector(asPoint() * scalar);
	}
	inline friend Vector operator*(const int& scalar, const Vector& vector) {
		return Vector(vector.asPoint() * scalar);
	}
	inline Vector operator/(const int& scalar) const {
		return Vector(asPoint() / scalar);
	}

	//Get methods
	inline double getX() const {
		return this->x;
	};
	inline double getY() const {
		return this->y;
	};
	inline double getZ() const {
		return this->z;
	};
	inline Point3D asPoint() const {
		return Point3D(getX(), getY(), getZ());
	};
};