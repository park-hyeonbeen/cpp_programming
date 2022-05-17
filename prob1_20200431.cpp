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
	//2���� �Է¹ް�, ��ȯ�� 10���� �� ����ϱ�
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
	//�迭�� �� ���ҿ� �ڸ����� �ش��ϴ� 2�� �ŵ����� ���ؼ� ���� ���ϱ�
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
	//�ڸ����� �˸´� 2�� �ŵ����� ���ϱ�
	unsigned int multiplr = 1;
	for (int i = 0; i < power; i++) {
		multiplr = multiplr * 2;
	}
	return multiplr;
}