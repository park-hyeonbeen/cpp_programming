#include "Line.h"


Line::Line() {
	l = Vector(0, 0, 0);
	l0 = Vector(0, 0, 0);
};
Line::Line(const Point& po1, const Point& po2) {
	l = po1.minus(po1, po2);
	l0 = po1;
};
Point Line::projectTo(const Point& po) {
	Vector temp;
	temp = temp.minus(l0, po);
	if (l.getVector(1) || l.getVector(2) || l.getVector(3))
		return l.plus(l.multiply(l.innerProduct(l,temp)/(l.magnitude()), l.normalize()), l0);
	else
		return po;
};
std::string Line::toString() {
	using namespace std;
	string temp = "Line: (" + to_string(l.getVector(1)) + "," + to_string(l.getVector(2)) + "," + to_string(l.getVector(3))
	+ ")t + (" + to_string(l0.getVector(1)) + "," + to_string(l0.getVector(2)) + "," + to_string(l0.getVector(3)) + ")";
	return temp;
};