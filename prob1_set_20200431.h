#pragma once
#include <string>

class MySet{
private:
	int* arry;
	int num;
	int size;
public:
	MySet() :num(0), size(0) { arry = NULL; };
	MySet(int* arry_, int a, int b);
	MySet(const MySet& M);
	~MySet() { delete[] arry; };
	MySet operator+(const MySet& S2);
	MySet operator+(const int E1);
	MySet operator-(const MySet& S2);
	MySet operator-(const int E1);
	MySet operator*(const MySet& S2);
	MySet operator=(const MySet& S2);
	bool operator==(const MySet& S2);
	bool contains(const MySet& S2);
	bool contains(const int E1);
	bool isEmpty();
	int getSize();
	std::string toString();
};