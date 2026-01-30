#include "pch.h"
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
Vector::Vector() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}