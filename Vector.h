#pragma once
#include <string>
#include <cmath>
class Vector {
private:
	double x, y, z;
public:
	Vector() {x = 0; y = 0; z = 0; };
	Vector(double _x, double _y, double _z);
	~Vector() {};
	double innerProduct(Vector v1, Vector v2)const;
	Vector outerProduct(Vector v1, Vector v2)const;
	Vector plus(Vector v1, Vector v2)const;
	Vector minus(Vector v1, Vector v2) const;
	Vector multiply(double s, Vector v)const;
	double magnitude()const;
	Vector normalize()const;
	double getVector(int t)const;
	std::string toString()const;
	bool operator=(const Vector& vec);
};
