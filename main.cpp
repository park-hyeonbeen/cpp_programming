#include <iostream>
#include "Fraction.h"
using namespace std;
int main() {
	Fraction fr1;
	fr1.store(1, 2);
	Fraction fr2(1, 4);
	Fraction fr3(2);
	Fraction fr4;

	fr1.print();
	cout << endl;
	fr2.print();
	cout << endl;
	fr3.print();
	cout << endl;
	fr4.print();
	cout << endl;

	cout << fr2.getnumer() << endl;
	cout << fr2.getdenom() << endl;
	cout << fr3.getnumer() << endl;
	cout << fr3.getdenom() << endl;
	fr3.setnumer(3);
	fr3.setdenom(4);
	fr3.print();
	(fr2 + fr1++).print();
	fr1.print();
	fr1 = fr1 - 1;
	(fr2 + ++fr1).print();
	fr1.print();
	fr1 = fr1 - 1;
	fr4 = fr1 + fr2 + fr3;
	fr4.print();
	cout << endl;
	fr3 = Fraction(3, 0);
	fr4 = fr3 - fr2 - fr1;
	fr4.print();
	cout << endl;
	fr4 = fr1 * fr2 * fr3;
	fr4.print();
	cout << endl;
	fr4 = fr1 / fr2 / fr3;
	fr4.print();
	cout << endl;
	fr4 = 1;
	fr4.print();
	cout << endl;
	fr4 += fr1 + fr2 + fr3;
	fr4.print();
	cout << endl;
            return 0;
	



	




}