#include "Vector.h"

Vector::Vector(double Vx, double Vy, double Vz) {
	this->x = Vx;
	this->y = Vy;
	this->z = Vz;
};
Vector::Vector(Point3D start, Point3D end) {
	Point3D asPoint = end - start;
	x = asPoint.getX();
	y = asPoint.getY();
	z = asPoint.getZ();
};
Vector::Vector(Point3D fromPoint) {
	this->x = fromPoint.getX();
	this->y = fromPoint.getY();
	this->z = fromPoint.getZ();
}

Vector Vector::cross(const Vector& other) const {
	return Vector(this->getY() * other.getZ() - this->getZ() * other.getY(), this->getX() * other.getZ() - this->getZ() * other.getX(), this->getX() * other.getY() - this->getY() * other.getX());
}

double Vector::dot(const Vector& other) const {
	return this->getX() * other.getX() + this->getY() * other.getY() + this->getZ() * other.getZ();
}