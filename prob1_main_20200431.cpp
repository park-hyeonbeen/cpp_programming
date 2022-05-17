#include "prob1_set_20200431.h"
#include <fstream>
#include <string>
#include <cstring>

void calc(char** command);
void check(char** command);
void reset(char* a);
void reset(char** a, int last);
void addtxt(char* a);
MySet makeMySet(char* a);
int getelement(char* a);

int main() {
	using namespace std;
	ifstream inputfile;
	ofstream output;
	char* command[6];
	char* str1 = NULL;
	char* str2 = NULL;
	int i = 0;
	int key = 2;
	for (int i = 0; i < 6; i++) {
		command[i] = new char[8];
	}

	inputfile.open("input_p1.txt");
	while (!inputfile.eof()) {
		inputfile >> command[i];
		str1 = command[i];
		 if (*command[i] == 'S'|| *command[i] == 'E')
			 addtxt(command[i]);
		
		 if (i != 0) {
			 str2 = command[i - 1];

			 if ((*str1 == 'S' || *str1 == 'E') && (*str2 == 'S' || *str2 == 'E')) {
				 if (key == 1 || key == 2) {
					 calc(command);
				 }
				 else if (key == 0) {
					 check(command);
				 }
				 output.open("output_p1_20200431.txt", std::ios::app);
				 output << std::endl;
				 output.close();
				 key = 1;
				 reset(command, i);
				 reset(str1);
				 reset(str2);
				 i = 0;
			 }
		 }
		
		 if (!strcmp(str1, "size") || !strcmp(str1, "isEmpty")) {
			if (key==1){
				calc(command);
				output.open("output_p1_20200431.txt", std::ios::app);
				output << std::endl;
				output.close();
			}
			if (key == 0) {
				check(command);
				output.open("output_p1_20200431.txt", std::ios::app);
				output << std::endl;
				output.close();
			}
			else if (key == 2);
			key = 0;
			reset(command, i);
			reset(str1);
			reset(str2);
			i = 0;
		}
		 i++;
	}
	if (key == 1||key == 2) {
		calc(command);
	}
	if (key == 0) {
		check(command);
	}
	return 0;
}

void calc(char** command) {
	using namespace std;
	int E;
    ofstream output;
	ofstream S;
	
	output.open("output_p1_20200431.txt", std::ios::app);
	 MySet S1(makeMySet(*command));

	if (!strcmp(*(command + 1),"+")) {
		MySet S2(makeMySet(*(command + 2)));
		output << (S1+S2).toString();
	}

	else if (!strcmp(*(command + 1),"-")) {
		MySet S2(makeMySet(*(command + 2)));
		output << (S1-S2).toString();
	}

	else if (!strcmp(*(command + 1),"*")) {
		MySet S2(makeMySet(*(command + 2)));
		output << (S1 * S2).toString();
	}

	else if (!strcmp(*(command + 1),"==")) {
		MySet S2(makeMySet(*(command + 2)));
		if (S1 == S2)
			output << "true";
		else
			output << "false";
	}

	else if (!strcmp(*(command + 1), "=")) {
		MySet S2(makeMySet(*(command + 2)));
		MySet S3(makeMySet(*(command + 4)));
		S.open(*command);
		
		if (!strcmp(*(command + 3), "+")) {
			S1 = S2 + S3;
		}

		else if (!strcmp(*(command + 3), "-")) {
			S1 = S2 - S3;
		}
		
		else if (!strcmp(*(command + 3), "*")) {
			S1 = S2 * S3;
		}
		else
		{
			S1 = S2;
		}
		output << S1.toString();
		S << S1.toString();
	}

	else if (!strcmp(*(command + 1), "contain")) {
		if (**(command + 2) == 'S') {
			MySet S2(makeMySet(*(command + 2)));
			if ((S1.contains(S2)))
				output << "true";
			else
				output << "false";
		}
		else {
			E = getelement(*(command + 2));
			if(S1.contains(E))
				output << "true";
			else
				output << "false";
		}

	}
	output.close();
	S.close();
}
	



void check(char** command) {
	std::ofstream output;
	output.open("output_p1_20200431.txt", std::ios::app);

	MySet S1(makeMySet(*(command+1)));

	if (!strcmp(*command, "isEmpty")) {
		if (S1.isEmpty())
			output << "true";
		else
			output << "false";
	}
	else if (!strcmp(*command, "size")) {
		output<<S1.getSize();
	}
	output.close();
}

void reset(char* a) {
	a = NULL;
}

void reset(char** a, int last) {

	char* temp = new char[8];
	for (int i = 0; i < 8; i++) {
		temp[i] = *(*(a+last)+i);
	}
	for (int i = 0; i < 6; i++) {
		delete[] a[i];
	}
	for (int i = 0; i < 6; i++) {
		a[i] = new char[8];
	}
	for (int i = 0; i < 8; i++) {
		*(*a + i) = temp[i];
	}
}

void addtxt(char* a) {
	*(a+2) = '.';
	*(a+3) = 't';
	*(a+4) = 'x';
	*(a+5) = 't';
	*(a + 6) = NULL;
}

MySet makeMySet(char* a) {
	std::string str;
	int E;
	int length =1;
	std::ifstream S;
	int* arry_;
	int empty;

	S.open(a);
	if (!S.good()) {
		int* emptyarry = new int[2]{ -1, -1 };
		return MySet(emptyarry, 2, 0);
	}
	else {
		S >> empty;
		if (S.eof()) {
			int* emptyarry = new int[2]{ -1, -1 };
			return MySet(emptyarry, 2, 0);
		}
		else
		{
			S.seekg(0, std::ios::beg);
			getline(S, str);
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == ' ')
					length++;
			}
			if (str.length() == 0)
				length = 0;
			arry_ = new int[length];
			S.seekg(0, std::ios::beg);
			for (int i = 0; !S.eof(); i++) {
				S >> arry_[i];
			}
			return MySet(arry_, length, length);
		}
	}
}

int getelement(char* a) {
	std::ifstream S;
	int E;
	S.open(a);
	S >> E;
	return E;
}


