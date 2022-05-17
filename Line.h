#pragma once
#include "Vector.h"
#define Point Vector

class Line {
private:
	Vector l, l0;
public:
	Line();
	Line(const Point& po1, const Point& po2);
	~Line() {};
	Point projectTo(const Point& po);
	std::string toString();
};