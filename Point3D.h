#pragma once
class Point3D {
private:
	double x, y, z;

public:
	Point3D(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};

	//Operators
	inline Point3D operator+(const Point3D& other) const {
		return Point3D(this->getX() + other.getX(), this->getY() + other.getY(), this->getZ() + other.getZ());
	}
	inline Point3D operator-(const Point3D& other) const {
		return Point3D(this->getX() - other.getX(), this->getY() - other.getY(), this->getZ() - other.getZ());
	}
	inline Point3D operator*(const Point3D& other) const {
		return Point3D(this->getX() * other.getX(), this->getY() * other.getY(), this->getZ() * other.getZ());
	}
	inline Point3D operator*(const int& other) const {
		return Point3D(this->getX() * other, this->getY() * other, this->getZ() * other);
	}
	inline friend Point3D operator*(const int& scalar, const Point3D& point) {
		return Point3D(point.getX() * scalar, point.getY() * scalar, point.getZ() * scalar);
	}
	inline Point3D operator/(const Point3D& other) const {
		return Point3D(this->getX() / other.getX(), this->getY() / other.getY(), this->getZ() / other.getZ());
	}
	inline Point3D operator/(const int& other) const {
		return Point3D(this->getX() / other, this->getY() / other, this->getZ() / other);
	}
	inline friend Point3D operator/(const int& scalar, const Point3D& point) {
		return Point3D(point.getX() / scalar, point.getY() / scalar, point.getZ() / scalar);
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
};