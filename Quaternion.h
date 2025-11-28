#pragma once
#include "Vector.h"
class Quaternion {
private: 
	double w, x, y, z;
public: 
	Quaternion(double w, double x, double y, double z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Quaternion(double w, Vector vec) {
		this->w = w;
		this->x = vec.getX();
		this->y = vec.getY();
		this->z = vec.getZ();
	}
	Quaternion(Vector vec) {
		this->x = vec.getX();
		this->y = vec.getY();
		this->z = vec.getZ();
	}
	//Methods
	inline Quaternion conjugate() const {
		return Quaternion(getW(), -getX(), -getY(), -getZ());
	}
	inline static Point3D apply(const Point3D& point, const Quaternion& qua) {
		const Quaternion normQua = qua.norm();
		Quaternion endQua = normQua * Quaternion(point) * normQua.conjugate();
		return Point3D(qua.getX(), qua.getY(), qua.getZ());
	}
	inline Point3D apply(const Point3D& point) const {
		return apply(point, *this);
	}
	inline Quaternion norm() const {
		double sum = sqrt(getW()*getW() + getX()*getX() + getY()*getY() + getZ()*getZ() );
		return Quaternion(getW()/sum, getX()/sum, getY()/sum, getZ()/sum);
	}

	//Operators
	inline Quaternion operator*(const Quaternion& other) const {
		return Quaternion(
			this->getW() * other.getW() - this->getX() * other.getX() - this->getY() * other.getY() - this->getZ() * other.getZ(), 
			this->getW() * other.getX() + this->getX() * other.getW() + this->getY() * other.getZ() - this->getZ() * other.getY(), 
			this->getW() * other.getY() - this->getX() * other.getZ() + this->getY() * other.getW() + this->getZ() * other.getX(), 
			this->getW() * other.getZ() + this->getX() * other.getY() - this->getY() * other.getX() + this->getZ() * other.getW()
		);
	}
	inline friend std::ostream& operator<<(std::ostream& os, const Quaternion& quaternion) {
		os << quaternion.getW() << (quaternion.getX() < 0 ? "" : "+") << quaternion.getX() << "i" << (quaternion.getY() < 0 ? "" : "+") << quaternion.getY() << "j" << (quaternion.getZ() < 0 ? "" : "+") << quaternion.getZ() << "k";
		return os;
	}
	inline bool operator==(const Quaternion& other) const {
		return (getW() == other.getW() && getX() == other.getX() && getY() == other.getY() && getZ() == other.getZ());
	}

	//Get Methods
	inline double getW() const {
		return this->w;
	}
	inline double getX() const {
		return this->x;
	}
	inline double getY() const {
		return this->y;
	}
	inline double getZ() const {
		return this->z;
	}
};