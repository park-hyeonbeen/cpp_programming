#include "Plane.h"

Plane::Plane() {
	Vector vec(0,0,0);
	n = vec;
	r0 = vec;
}
;
Plane::Plane(const Point& po1, const Point& po2, const Point& po3) {
	r0 = po1;
	n = po1.outerProduct(po1.minus(po1, po2), po2.minus(po2, po3));
}
Point Plane::projectTo(const Point& po) {
	if (n.getVector(1) || n.getVector(2) || n.getVector(3))
	{
		Vector temp = r0.minus(r0, po);
		Point point1 =  n.plus(n.multiply(n.innerProduct(n, temp) / (n.magnitude()), n.normalize()), po);
	    return point1;
	}
	else
		return po;
};
std::string Plane::toString() {
	using namespace std;
	std::string temp = "Plane: (" + to_string(n.getVector(1)) + "," + to_string(n.getVector(2)) + "," + to_string(n.getVector(3)) +
		")(r - (" + to_string(r0.getVector(1)) + "," + to_string(r0.getVector(2)) + "," + to_string(r0.getVector(3)) + "))=0";
	return temp;
};
