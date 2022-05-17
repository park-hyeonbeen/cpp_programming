#include "prob1_set_20200431.h"


MySet::MySet(int* arry_, int a , int b) {
	arry = new int[a];
	for (int i = 0; i < a; i++) {
		arry[i] = arry_[i];
	}
	num = b;
	size = a;
};

MySet::MySet(const MySet& M) {
	arry = new int[M.size];
	num = M.num;
	size = M.size;
};

MySet MySet::operator+(const MySet& S2) {
	int size_ = size+ S2.size;
	int num_ = 0;
	int* arry_ = new int[size + S2.size];
	MySet M((*this - (*this * S2)));
	for (int i = 0; i < size; i++) {
		arry_[i] = M.arry[i];
		if (arry_[i] != -1)
			num_++;
	}
	for (int i = size, j = 0; j < S2.size; i++, j++) {
		arry_[i] = S2.arry[j];
		num_++;
	}

	return MySet(arry_, size_, num_);

};
MySet MySet::operator+(const int E1) {
	int* arry_ = new int[size];
	int size_ = size;
	int num_ = num;

	for (int i = 0; i < size; i++) {
		arry_[i] = arry[i];
	}

	for (int i = 0; i<size; i++) {
		if (arry[i] == E1)
			return MySet(arry_, size, num);
}
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		temp[i] = arry[i];
	}
	delete[] arry_;
	arry_ = new int[size + 1];
	for (int i = 0; i < size; i++) {
		arry_[i] = temp[i];
	}
	arry_[size] = E1;
	size_++;
	num_++;
	return MySet(arry_, size_, num_);
};
MySet MySet::operator-(const MySet& S2) {
	int* arry_ = new int[size];
	int size_ = size;
	int num_ = num;
	for (int i = 0; i < size; i++) {
		arry_[i] = arry[i];
	}
	for (int i = 0; i<size; i++) {
		for (int j = 0; j<S2.size; j++) {
			if (arry_[i] == S2.arry[j]) {
				if (arry_[i] != -1)
					num_--;
				arry_[i] = -1;
				break;
			}
		}
	}
	return MySet(arry_,size_,num_);
};
MySet MySet::operator-(const int E1) {
	int* arry_ = new int[size];
	int size_ = size;
	int num_ = num;
	for (int i = 0; i < size; i++) {
		arry_[i] = arry[i];
	}
	for (int i = 0;i<size; i++) {
		if (arry_[i] == E1) {
			arry_[i] = -1;
			num_--;
		}
	}
	return MySet(arry_, size_, num_);
};
MySet MySet::operator*(const MySet& S2) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < S2.size; j++) {
			if (arry[i] == S2.arry[j]) {
				count++;
			}
		}
	}
	if (count == 0) {
		int* arry_ = new int[2]{ -1, -1 };
		return MySet(arry_, 2, 0);
	}
	else{
	int* arry_ = new int[count];
	int size_ = count;
	int num_ = 0;
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < S2.size; j++) {
			if (arry[i] == S2.arry[j]) {
				arry_[k] = arry[i];
				num_++;
				k++;
			}
		}
	}
	return MySet(arry_, size_, num_);
}
};
MySet MySet::operator=(const MySet& S2) {
	int* arry_;
	int size_;
	int num_;
	delete[] arry;
	arry = new int[S2.size];
	for (int i = 0; i < S2.size; i++) {
		arry[i] = S2.arry[i];
	}
	size = S2.size;
	num = S2.num;
	arry_ = new int[size];
	for (int i = 0; i < size; i++) {
		arry_[i] = arry[i];
	}
	size_ = size;
	num_ = num;
	return MySet(arry_,size_,num_);
};
bool MySet::operator==(const MySet& S2) {
	int k = 0;
	if (num != S2.num) {
		return false;
	}
	else
	{
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < S2.size; j++) {
				if (arry[i] == S2.arry[j])
					k++;
			}
		}
		if (k == num||(num == 0 && S2.num==0))
			return true;
		else
			return false;
	}
};
bool MySet::contains(const MySet& S2) {
	int k = 0;
	for (int i = 0; i<S2.size; i++) {
		for (int j = 0; j<size; j++) {
			if (arry[j] == S2.arry[i])
				k++;
		}
	}
	if (k == S2.num||S2.num == 0)
		return true;
	else
		return false;
};
bool MySet::contains(const int E1) {
	for (int i = 0; i<size; i++) {
			if (arry[i] == E1)
				return true;
		}
	return false;
};
bool MySet::isEmpty() {
	if (num)
		return false;
	else
		return true;
};
int MySet::getSize() {
	return num;
};
std::string MySet::toString() {
	std::string str("");
	for (int i = 0; i<size; i++) {
		if(arry[i]!=-1)
		str += std::to_string(arry[i])+" ";
	}
	if(str!="")
		str.pop_back();
	return str;
};