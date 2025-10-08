#pragma once
#include "Point3D.h"
class Vector {
private: 
	double x, y, z;

public: 
	Vector(double Vx, double Vy, double Vz);
	Vector(Point3D start, Point3D end);
	Vector(Point3D fromPoint);

	//Methods
	Vector cross(const Vector& other) const;
	inline static Vector cross(const Vector& vec1, const Vector& vec2) {
		return vec1.cross(vec2);
	}
	double dot(const Vector& other) const;
	inline static double dot(const Vector& vec1, const Vector& vec2) {
		return vec1.dot(vec2);
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