#pragma once
#include <string>
#include <vector>
template<typename T>
class MyMatrix {
private:
	std::vector<std::vector<T>> v;
	int dimension;
public:
	MyMatrix();
	MyMatrix(std::vector<std::vector<T>> v);
	~MyMatrix();
	MyMatrix operator+(const MyMatrix& M2);

	template<typename T2>
	MyMatrix<long long> operator+(const MyMatrix<T2>& M2);

	MyMatrix operator-(const MyMatrix& M2);

	template<typename T2>
	MyMatrix<long long> operator-(const MyMatrix<T2>& M2);

	MyMatrix operator*(const MyMatrix& M2);

	template< typename T2>
	MyMatrix<long long> operator*(const MyMatrix<T2>& M2);
	
	template<typename T2>
	MyMatrix<T2> operator=(const MyMatrix<T2>& M2);

	MyMatrix transpose();
	int Getdimension ()const;
	std::vector<std::vector<T>> Getvector()const;
	std::string toString();
};