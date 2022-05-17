#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

unsigned int binry_to_dec(std::string binrystr);
unsigned int power_2(int power);


int main() {
	using namespace std;
	ifstream infile;
	ofstream outfile;
	unsigned int dec;
	string binrystr;


	infile.open("input.txt");
	outfile.open("output.txt");
	//2진수 입력받고, 변환된 10진수 값 출력하기
	while (infile.good()) {
		infile >> binrystr;
		dec = binry_to_dec(binrystr);
		outfile << dec << endl;
	}
	infile.close();
	outfile.close();
	return 0;

}

unsigned int binry_to_dec(std::string binrystr) {
	//배열의 각 원소에 자릿수에 해당하는 2의 거듭제곱 곱해서 총합 구하기
	int bit;
	unsigned int dec = 0;
	int power;
	for (int i = 0; i< binrystr.size(); i++) {
		bit = binrystr[i]-48;
		power = binrystr.size() - 1 - i;
		dec += bit * power_2(power);
	}

	return dec;
}

unsigned int power_2(int power) {
	//자릿수에 알맞는 2의 거듭제곱 구하기
	unsigned int multiplr = 1;
	for (int i = 0; i < power; i++) {
		multiplr = multiplr * 2;
	}
	return multiplr;
}