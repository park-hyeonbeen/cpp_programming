#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void merge_sort(string how, int* sort, int size);
void divide(string how, int* insorted, int size);
void merge_up(int* sort, int* arr1, int* arr2, int size1, int size2);
void merge_down(int* sort, int* arr1, int* arr2, int size1, int size2);

int main() {
	//class, 변수선언 및 파일열기
	ifstream infile;
	ofstream outfile;
	string how;
	string line;
	string piece;
	int size = 1;
	int strlen;
	

	infile.open("input.txt");
	
	while (infile.good()) {
		//how와 line입력받고 line 파싱, 정수형으로 sort에 저장
		size = 1;
		infile >> how;
		getline(infile, line);
		getline(infile, line);
		strlen = line.size();
		for (int i = 0; i < strlen; i++) {
			if (line[i] == ' ')
				size++;
		}

		int* sort = new int[size];
		stringstream ss(line);

		for (int i = 0; i<size; i++) {
			ss >> piece;
			sort[i] = stoi(piece);
		}
		//merge_sort 호출 후 결과 출력
		merge_sort(how, sort, size);
		for (int i = 0; i < size; i++)
			outfile << sort[i] << " ";
		outfile << endl;
		delete[] sort;
	}
	infile.close();
	outfile.close();
	return 0;
}

void merge_sort(string how, int* sort, int size){
	//size가 1일 때와 아닐 때로 나눠 아닐 때 divide호출
	if (size == 1)
		return;
	else {
		divide(how, sort, size);
		return;		
	}


}
void divide(string how, int* sort, int size) {
	int size_org = size;
	size = size/ 2;
	int size1 = size;
	int size2 = size;
	if (size_org != 1) {
		//sort를 반으로 나눠 각각 새로운 배열에 저장하고 그 배열들에 대해 다시 divide 호출
		int* divided1;
		int* divided2 = new int[size2];
		if (size_org % 2) {
			divided1 = new int[size + 1];
			size1 = size + 1;
			for (int i = 0; i < size1; i++) {
				divided1[i] = sort[i];
			}
			for (int i = 0; i < size2; i++) {
					divided2[i] = sort[i+size1];
			}
		}
		else {
			divided1 = new int[size];
			for (int i = 0; i < size2; i++) {
				divided1[i] = sort[i];
			}
			for (int i = 0; i < size2; i++) {
					divided2[i] = sort[i+size2];
				}
		}

		divide(how, divided1, size1);
		divide(how, divided2, size2);
		//return 받은 배열들에 대해 merge수행
		if (how == "down")
			merge_down(sort, divided1, divided2, size1, size2);
		else if (how == "up")
			merge_up(sort, divided1, divided2, size1, size2);
	}
	//배열의 길이가 1이되면 return
		return;
}

void merge_down(int* sort, int* arr1, int* arr2, int size1, int size2) {
	int* temp1 = arr1;
	int* temp2 = arr2;
	int arr1count = size1;
	int arr2count = size2;
	for (int i = 0;i<size1+size2 ;i++) {
		//arr1과 arr2의 맨 앞 원소 비교를 통해 상위 배열에 입력, arr1 또는 arr2의 주소 증가
		//count로 모든 원소가 비교되었는지 확인
		if (arr1count == 0) {
			sort[i] = arr2[0];
			arr2 = arr2 + 1;
			arr2count--;
		}
		else if (arr2count == 0) {
			sort[i] = arr1[0];
			arr1 = arr1 + 1;
			arr1count--;
		}
		else {
		if (arr1[0] > arr2[0]) {
			sort[i] = arr1[0];
			arr1 = arr1 + 1;
			arr1count--;
		}
		else if (arr1[0] < arr2[0]) {
			sort[i] = arr2[0];
			arr2 = arr2 + 1;
			arr2count--;
		}
		else {
			sort[i] = arr1[0];
			sort[i + 1] = arr1[0];
			i++;
			arr1 = arr1 + 1;
			arr2 = arr2 + 1;
			arr1count--;
			arr2count--;
		}
		}
	}
	delete[] temp1;
	delete[] temp2;
}

void merge_up(int* sort, int* arr1, int* arr2, int size1, int size2) {
	int* temp1 = arr1;
	int* temp2 = arr2;
	int arr1count = size1;
	int arr2count = size2;
	for (int i = 0; i < size2+size1; i++) {
		//arr1과 arr2의 맨 앞 원소 비교를 통해 상위 배열에 입력, arr1 또는 arr2의 주소 증가
		//count로 모든 원소가 비교되었는지 확인
		if (arr1count == 0) {
			sort[i] = arr2[0];
			arr2 = arr2 + 1;
			arr2count--;
		}
		else if (arr2count == 0) {
			sort[i] = arr1[0];
			arr1 = arr1 + 1;
			arr1count--;
		}
		else {
			if (arr1[0] < arr2[0]) {
				sort[i] = arr1[0];
				arr1 = arr1 + 1;
				arr1count--;
			}
			else if (arr1[0] > arr2[0]) {
				sort[i] = arr2[0];
				arr2 = arr2 + 1;
				arr2count--;
			}
			else {
				sort[i] = arr1[0];
				sort[i + 1] = arr1[0];
				i++;
				arr1 = arr1 + 1;
				arr2 = arr2 + 1;
				arr1count--;
				arr2count--;
			}
		}
	}
	delete[] temp1;
	delete[] temp2;
}