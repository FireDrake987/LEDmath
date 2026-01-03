#include "pch.h"
#include "Quaternion.h"

Quaternion::Quaternion(double w, double x, double y, double z) {
	this->w = w;
	this->x = x;
	this->y = y;
	this->z = z;
}
Quaternion::Quaternion(double w, Vector vec) {
	this->w = w;
	this->x = vec.getX();
	this->y = vec.getY();
	this->z = vec.getZ();
}
Quaternion::Quaternion(Vector vec) {
	this->x = vec.getX();
	this->y = vec.getY();
	this->z = vec.getZ();
	this->w = 0;
}