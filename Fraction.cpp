#include <iostream>
#include "fraction.h"

Fraction::Fraction() { 
	numerator = 0; 
	denominator = 1; };
Fraction::Fraction(int numer) { 
	numerator = numer; 
	denominator = 1; };
Fraction::Fraction(int numer, int denom) {
	numerator = numer;
	denominator = denom;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
}
Fraction::Fraction(const Fraction& copyForm) {
	numerator = copyForm.numerator;
	denominator = copyForm.denominator;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
};
Fraction::~Fraction() {};
void Fraction::store(int numer, int denom) {
	numerator = numer;
	denominator = denom;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
};
int Fraction::getnumer() {
	return numerator;
};
int Fraction::getdenom() {
	return denominator;
}
void Fraction::setnumer(int numer) {
	numerator = numer;
};
void Fraction::setdenom(int denom) {
	denominator = denom;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
};
Fraction Fraction::operator++() {
	numerator += denominator;
	return *this;
};
bool Fraction::operator=(const Fraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return true;
};
Fraction Fraction::operator+(const Fraction& f) const {
	Fraction temp(numerator*f.denominator + f.numerator*denominator, denominator*f.denominator);
	return temp;
	if (temp.denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
};
Fraction Fraction::operator-(const Fraction& f) const {
	Fraction temp(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
	if (temp.denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return temp;
};
Fraction Fraction::operator*(const Fraction& f) const {
	Fraction temp(numerator * f.numerator, denominator * f.denominator);
	if (temp.denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return temp;
};
Fraction Fraction::operator/(const Fraction& f) const {
	Fraction temp(numerator * f.denominator, denominator * f.numerator);
	if (temp.denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return temp;
};

bool Fraction::operator+=(const Fraction& f){
	numerator = numerator * f.denominator + f.numerator * denominator;
	denominator = denominator * f.denominator;
	if (denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return true;
};

Fraction Fraction::operator++(int) {
	Fraction temp = *this;
	numerator += denominator;
	if (temp.denominator == 0) {
		std::cout << "error!";
		quick_exit(0);
	}
	return temp;
};
