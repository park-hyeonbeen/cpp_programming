#pragma once
#include "Vector.h"
#define Point Vector

class Plane{
private:
	Vector n;
	Vector r0;
public:
	Plane();
	Plane(const Point& po1, const Point& po2, const Point& po3);
	~Plane() {};
	Point projectTo(const Point& po);
	std::string toString();
};