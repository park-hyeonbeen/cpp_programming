#pragma once
#include <iostream>
class Fraction 
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int numer);
	Fraction(int numer, int denom);
	Fraction(const Fraction& copyForm);
	~Fraction();
	void store(int numer, int denom);
	inline void print() const { std::cout << numerator << "/" << denominator<<std::endl; };
	int getnumer();
	int getdenom();
	void setnumer(int numer);
	void setdenom(int denom);
	Fraction operator++();
	bool operator=(const Fraction& f);
	Fraction operator+(const Fraction& f) const;
	Fraction operator-(const Fraction& f) const;
	Fraction operator*(const Fraction& f) const;
	Fraction operator/(const Fraction& f) const;
	bool operator+=(const Fraction& f);
	Fraction operator++(int);
};