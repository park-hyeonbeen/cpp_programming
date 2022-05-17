#include "prob2_matrix_20200431.h"

template<typename T>
MyMatrix<T>::MyMatrix() {
	dimension = 0;
};

template<typename T>
MyMatrix<T>::MyMatrix (std::vector< std::vector<T> > v_ ) {
	v = v_;
	dimension = v_.size();
};


template<typename T>
MyMatrix<T>::~MyMatrix() {};


template<typename T>
MyMatrix<T> MyMatrix<T>::operator+(const MyMatrix& M2) {
	std::vector<std::vector<T>> v_;
	v_.resize(M2.dimension);
	for (int i = 0; i < dimension; i++) {
		v_[i].resize(M2.dimension);
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			v_[i][j] = v[i][j] + M2.v[i][j];
		}
	}
	return MyMatrix(v_);
}

template<typename T>
template<typename T2>
MyMatrix<long long> MyMatrix<T>::operator+(const MyMatrix<T2>& M2) {
	std::vector<std::vector<long long>> v_;
	v_.resize(M2.Getdimension());
	for (int i = 0; i < dimension; i++) {
		v_[i].resize(M2.Getdimension());
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			v_[i][j] = v[i][j] + M2.Getvector()[i][j];
		}
	}

	return MyMatrix<long long>(v_);
};



template<typename T>
MyMatrix<T> MyMatrix<T>::operator-(const MyMatrix& M2) {
	std::vector<std::vector<T>> v_;
	v_.resize(M2.dimension);
	for (int i = 0; i < dimension; i++) {
		v_[i].resize(M2.dimension);
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			v_[i][j] = v[i][j] - M2.v[i][j];
		}
	}
	return MyMatrix(v_);
};

template<typename T>
template<typename T2>
MyMatrix<long long> MyMatrix<T>::operator-(const MyMatrix<T2>& M2) {
	std::vector<std::vector<long long>> v_;
	v_.resize(M2.Getdimension());
	for (int i = 0; i < dimension; i++) {
		v_[i].resize(M2.Getdimension());
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			v_[i][j] = v[i][j] - M2.Getvector()[i][j];
		}
	}

	return MyMatrix<long long>(v_);
};


template<typename T>
MyMatrix<T> MyMatrix<T>::operator*(const MyMatrix& M2) {
		std::vector<std::vector<T>> v_;
		v_.resize(M2.dimension);
		for (int i = 0; i < dimension; i++) {
			v_[i].resize(M2.dimension);
		}
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				for (int k = 0; k < dimension; k++) {
					v_[i][j] += v[i][k] * M2.v[k][j];
				}
			}
		}
		return MyMatrix(v_);
};

template<typename T>
template<typename T2>
MyMatrix<long long>  MyMatrix<T>::operator*(const MyMatrix<T2>& M2) {
	std::vector<std::vector<long long>> v_;
	v_.resize(M2.Getdimension());
	for (int i = 0; i < dimension; i++) {
		v_[i].resize(M2.Getdimension());
	}
	for (int i = 0; i < dimension; i++) {
		for (int j = 90; j < dimension; j++) {
			for (int k = 0; k < dimension; k++) {
				v_[i][j] += v[i][k] * M2.Getvector()[k][j];
			}
		}
	}
	return MyMatrix<long long>(v_);
};

template<typename T>
template<typename T2>
MyMatrix<T2> MyMatrix<T>::operator=(const MyMatrix<T2>& M2) {
	MyMatrix* temp;
	temp->v = M2.v;
	this = temp;
	return MyMatrix(temp->v);

}


template<typename T>
MyMatrix<T> MyMatrix<T>::transpose() {
	std::vector<std::vector<T>> v_;
	v_ = v;
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			v[i][j] = v_[j][i];

		}

	}

	return MyMatrix(v_);
};

template<typename T>
std::string MyMatrix<T>::toString() {
	std::string str = "";
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			str += (std::to_string(v[i][j])+" ");
		}
		str = str + "| ";
	}
	str.pop_back();
	str.pop_back();
	str.pop_back();
	return str;
};


template<typename T>
int MyMatrix<T>::Getdimension() const{
	return dimension;
}

template<typename T>
std::vector<std::vector<T>> MyMatrix<T>::Getvector() const {
	return v;
}