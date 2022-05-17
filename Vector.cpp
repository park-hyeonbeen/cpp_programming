#include "Vector.h"

Vector::Vector(double _x, double _y, double _z) {
	x = _x;
	y = _y;
	z = _z;
};

double Vector::innerProduct(Vector v1, Vector v2) const {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
};

Vector Vector::outerProduct(Vector v1, Vector v2)const {
	Vector temp(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	return temp;
};

Vector Vector::plus(Vector v1, Vector v2)const {
	Vector temp(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return temp;
};

Vector Vector::minus(Vector v1, Vector v2) const {
	Vector temp(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return temp;
};

Vector Vector::multiply(double s, Vector v)const {
	Vector temp(s * v.x, s * v.y, s * v.z);
	return temp;
};

double Vector::magnitude() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
};
Vector Vector::normalize() const {
	double mag = this->magnitude();
	Vector temp(x / mag, y / mag, z / mag);
	return temp;
};

double Vector::getVector(int t) const {
	switch (t){
	case 1:
		return x;
	case 2:
		return y;
	case 3:
		return z;
	default:
		return 0;
	}
}

std::string Vector::toString() const {
	std::string temp1 = "";
	std::string temp2 = "";
	std::string temp3 = "";
	std::string temp;
	temp1 = std::to_string(x);
	temp2 = std::to_string(y);
	temp3 = std::to_string(z);
	temp = "(" + temp1 + "," + temp2 + "," + temp3+")";
	return temp;
};

bool Vector::operator=(const Vector& vec) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
	return true;
};