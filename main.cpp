#include <iostream>
#include "Vector.h"
#include "line.h"
#include "Plane.h"

using namespace std;
int main() {
	Point p1(0, 0, 0);
	Point p2(2, 0, -1);
	Point p3(0, 1, 0);
	Point p4(2, 4, 6);
	cout << p1.innerProduct(p2, p3) << endl;
	cout << (p1.outerProduct(p2, p3)).toString() << endl;
	cout << (p1.plus(p2, p3)).toString() << endl;
	cout << (p1.minus(p2, p3)).toString() << endl;
	cout << p4.magnitude();
	cout << (p4.normalize()).toString()<<endl;

	Line l1(p1, p2);
	Line l2;
	cout << l1.toString() << endl;
	cout << l2.toString() << endl;
	cout << (l1.projectTo(p4)).toString()<<endl;
	Plane pl1(p1, p2, p3);
	Plane pl2;
	cout << pl1.toString() << endl;
	cout << pl2.toString() << endl;
	cout << (pl1.projectTo(p4)).toString()<<endl;
	return 0;
}
