#include "prob2_matrix_20200431.h"
#include "prob2_matrix_20200431.cpp""
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>


int check_int(std::string M);
std::vector<std::vector<int>> MakeMyMatint(std::string M_);
std::vector<std::vector<long long>> MakeMyMatlong(std::string M_);
template <typename T>
int digonal(MyMatrix<T> a);
int No_square(std::string str);

int main() {
	std::string command;
	std::string newcommand = "";
	std::string mat;
	std::ifstream infile;
	std::ofstream outfile;
	std::ofstream M;
	int j = 0;
	int count = 0;
	long long type;
	std::string piece1 = "";
	std::string piece2 = "";
	std::string piece3 = "";
	std::string piece4 = "";
	std::string piece5 = "";
	std::string piece6 = "";
	std::string piece7 = "";
	std::string lastpiece = "";
	std::string piece_ = "";
	MyMatrix<int>* Mat;
	int error = 1;
	int check[3];

	for (int i = 0; i < 3; i++) {
		check[i] = -1;
	}

	infile.open("input_p2.txt");
	outfile.open("output_p2.txt");

	while(!infile.eof()){
		if (error == 0)
			outfile << "LOST_ELEMENT" << std::endl;
		if (error == -1)
			outfile << "NOT_SQUARE" << std::endl;
		if (error == -2)
			outfile << "NO_SQUARE" << std::endl;
		if (error == -3)
			outfile << "UNAVAILABLE_OPERATION" << std::endl;
		error = 1;
		newcommand = "";
		for (int i = 0; i < 3; i++) {
			check[i] = -1;
		}
		count = 0;
		int u = 0;
		std::getline(infile, command);
		for (int i=0; i < command.length(); i++) {
			if (command[i] == 'M') {
				count++;
			}
		}

		std::stringstream ss(command);
		for(int i = 0; !ss.eof();i++){
			ss >> piece1;		
			if (piece1[0] == 'M') {
				check[u] = check_int(piece1);
				u++;
			}
		}

		std::stringstream ss_(command);
		for (int i = 0; !ss_.eof(); i++) {
			ss_ >> piece_;
			if (piece_ != "TRANS") {
				newcommand += piece_+" ";
			}
		}
		
		if (check[0] == 1) {
			std::string piece = "";
			std::string piece_ = "";
			int Tr = 0;
			std::stringstream ss2(command);
			for (int i = 0; !ss2.eof(); i++) {
				ss2 >> piece;
				if (piece[0] == 'M') {
					if (piece_[0] == 'T') {
						Tr = 1;
					}
					break;
				}
				piece_ = piece;
			}

			if ((error = No_square(piece)) != 1)
				continue;
			MyMatrix<int> Mat1(MakeMyMatint(piece));
			if ((error = digonal(Mat1)) != 1)
				continue;

			if (Tr == 1)
				Mat1.transpose();
			Tr = 0;

			if (check[1] == 1) {
				std::string piece = "";
				std::string piece_ = "";
				int Tr = 0;
				for (int i = 0; !ss2.eof(); i++) {
					ss2 >> piece;
					if (piece[0] == 'M') {
						if (piece_[0] == 'T') {
							Tr = 1;
						}
						break;
					}
					piece_ = piece;
				}
				if ((error = No_square(piece)) != 1)
					continue;
				MyMatrix<int> Mat2(MakeMyMatint(piece));
				if ((error = digonal(Mat2)) != 1)
					continue;

				if (Tr == 1)
					Mat2.transpose();
				Tr = 0;

				if (check[2] == 1) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<int> Mat3(MakeMyMatint(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;


					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}
						
						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if(i!=Mat2.Getdimension()-1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}


				}
				else if (check[2] == 0) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<long long> Mat3(MakeMyMatlong(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;


					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}

						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}

				}


				if (count == 1) {
					outfile << Mat1.toString() << std::endl;
				}

				if (count == 2) {

					std::stringstream ss2(newcommand);
					for (int i = 0; i < 4; i++) {
						ss2 >> piece5;
						if (i == 0) {
							piece4 = piece5;
						}
						if (i == 1) {
							piece3 = piece5;
						}
					}

					if (piece3 == "=") {
						M.open(piece4 + ".txt");
						for (int i = 0; i < Mat2.Getdimension(); i++) {
							for (int j = 0; j < Mat2.Getdimension(); j++) {
								M << Mat2.Getvector()[i][j];
								if (j != Mat2.Getdimension() - 1)
									M << " ";
							}
							if (i != Mat2.Getdimension() - 1)
								M << std::endl;
						}
						outfile << Mat2.toString() << std::endl;
						M.close();

					}

					if (Mat1.Getdimension() != Mat2.Getdimension()) {
						error = -3;
						continue;
					}

					else if (piece3 == "+") {
						outfile << (Mat1 + Mat2).toString() << std::endl;
					}

					else if (piece3 == "-") {
						outfile << (Mat1 - Mat2).toString() << std::endl;
					}

					else if (piece3 == "*") {
						outfile << (Mat1 * Mat2).toString() << std::endl;
					}
				}
			}
			else if (check[1] == 0) {
				std::string piece = "";
				std::string piece_ = "";
				int Tr = 0;
				for (int i = 0; !ss2.eof(); i++) {
					ss2 >> piece;
					if (piece[0] == 'M') {
						if (piece_[0] == 'T') {
							Tr = 1;
						}
						break;
					}
					piece_ = piece;
				}
				if ((error = No_square(piece)) != 1)
					continue;
				MyMatrix<long long> Mat2(MakeMyMatlong(piece));
				if ((error = digonal(Mat2)) != 1)
					continue;

				if (Tr == 1)
					Mat2.transpose();
				Tr = 0;

				if (check[2] == 1) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<int> Mat3(MakeMyMatint(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;


					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}

						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}
				}
				else if (check[2] == 0) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<long long> Mat3(MakeMyMatlong(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;


					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}

						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}
				}

				if (count == 1) {
					outfile << Mat1.toString() << std::endl;
				}

				if (count == 2) {

					std::stringstream ss2(newcommand);
					for (int i = 0; i < 4; i++) {
						ss2 >> piece5;
						if (i == 0) {
							piece4 = piece5;
						}
						if (i == 1) {
							piece3 = piece5;
						}
					}

					if (piece3 == "=") {
						M.open(piece4 + ".txt");
						for (int i = 0; i < Mat2.Getdimension(); i++) {
							for (int j = 0; j < Mat2.Getdimension(); j++) {
								M << Mat2.Getvector()[i][j];
								if (j != Mat2.Getdimension() - 1)
									M << " ";
							}
							if (i != Mat2.Getdimension() - 1)
								M << std::endl;
						}
						outfile << Mat2.toString() << std::endl;
						M.close();

					}

					if (Mat1.Getdimension() != Mat2.Getdimension()) {
						error = -3;
						continue;
					}

					else if (piece3 == "+") {
						outfile << (Mat1 + Mat2).toString() << std::endl;
					}

					else if (piece3 == "-") {
						outfile << (Mat1 - Mat2).toString() << std::endl;
					}

					else if (piece3 == "*") {
						outfile << (Mat1 * Mat2).toString() << std::endl;
					}
				}
			}


			if (count == 1) {
				outfile << Mat1.toString() << std::endl;
			}
		}
		else if(check[0] == 0) {
			std::string piece = "";
			std::string piece_ = "";
			int Tr = 0;
			std::stringstream ss2(command);
			for (int i = 0; !ss2.eof(); i++) {
				ss2 >> piece;
				if (piece[0] == 'M') {
					if (piece_[0] == 'T') {
						Tr = 1;
					}
					break;
				}
				piece_ = piece;
			}
			if ((error = No_square(piece)) != 1)
				continue;
			MyMatrix<long long> Mat1(MakeMyMatlong(piece));
			if ((error = digonal(Mat1)) != 1)
				continue;

			if (Tr == 1)
				Mat1.transpose();
			Tr = 0;

			if (check[1] == 1) {
				std::string piece = "";
				std::string piece_ = "";
				int Tr = 0;
				for (int i = 0; !ss2.eof(); i++) {
					ss2 >> piece;
					if (piece[0] == 'M') {
						if (piece_[0] == 'T') {
							Tr = 1;
						}
						break;
					}
					piece_ = piece;
				}
				if (error = No_square(piece) != 1)
					continue;
				MyMatrix<int> Mat2(MakeMyMatint(piece));
				if ((error = digonal(Mat2)) != 1)
					continue;

				if (Tr == 1)
					Mat2.transpose();
				Tr = 0;

				if (check[2] == 1) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<int> Mat3(MakeMyMatint(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;

					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}

						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}
				}
				else if (check[2] == 0) {
					std::string piece = "";
					std::string piece_ = "";
					int Tr = 0;
					for (int i = 0; !ss2.eof(); i++) {
						ss2 >> piece;
						if (piece[0] == 'M') {
							if (piece_[0] == 'T') {
								Tr = 1;
							}
							break;
						}
						piece_ = piece;
					}
					if ((error = No_square(piece)) != 1)
						continue;
					MyMatrix<long long> Mat3(MakeMyMatlong(piece));
					if ((error = digonal(Mat3)) != 1)
						continue;

					if (Tr == 1)
						Mat3.transpose();
					Tr = 0;


					if (count == 1) {
						outfile << Mat1.toString() << std::endl;
					}

					if (count == 2) {

						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece5;
							if (i == 0) {
								piece4 = piece5;
							}
							if (i == 1) {
								piece3 = piece5;
							}
						}

						if (piece3 == "=") {
							M.open(piece4 + ".txt");
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << Mat2.Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << Mat2.toString() << std::endl;
							M.close();

						}

						if (Mat1.Getdimension() != Mat2.Getdimension()) {
							error = -3;
							continue;
						}

						else if (piece3 == "+") {
							outfile << (Mat1 + Mat2).toString() << std::endl;
						}

						else if (piece3 == "-") {
							outfile << (Mat1 - Mat2).toString() << std::endl;
						}

						else if (piece3 == "*") {
							outfile << (Mat1 * Mat2).toString() << std::endl;
						}
					}

					if (count == 3) {
						std::stringstream ss2(newcommand);
						for (int i = 0; i < 4; i++) {
							ss2 >> piece6;
							if (i == 0) {
								piece7 = piece6;
							}
						}

						if (Mat2.Getdimension() != Mat3.Getdimension()) {
							error = -3;
							continue;
						}

						M.open(piece7 + ".txt");

						if (piece6 == "+") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 + Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 + Mat3).toString() << std::endl;
						}

						else if (piece6 == "-") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 - Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 - Mat3).toString() << std::endl;
						}

						else if (piece6 == "*") {
							for (int i = 0; i < Mat2.Getdimension(); i++) {
								for (int j = 0; j < Mat2.Getdimension(); j++) {
									M << (Mat2 * Mat3).Getvector()[i][j];
									if (j != Mat2.Getdimension() - 1)
										M << " ";
								}
								if (i != Mat2.Getdimension() - 1)
									M << std::endl;
							}
							outfile << (Mat2 * Mat3).toString() << std::endl;
						}
						M.close();
					}
				}

				if (count == 1) {
					outfile << Mat1.toString() << std::endl;
				}

				if (count == 2) {

					std::stringstream ss2(newcommand);
					for (int i = 0; i < 4; i++) {
						ss2 >> piece5;
						if (i == 0) {
							piece4 = piece5;
						}
						if (i == 1) {
							piece3 = piece5;
						}
					}

					if (piece3 == "=") {
						M.open(piece4 + ".txt");
						for (int i = 0; i < Mat2.Getdimension(); i++) {
							for (int j = 0; j < Mat2.Getdimension(); j++) {
								M << Mat2.Getvector()[i][j];
								if (j != Mat2.Getdimension() - 1)
									M << " ";
							}
							if (i != Mat2.Getdimension() - 1)
								M << std::endl;
						}
						outfile << Mat2.toString() << std::endl;
						M.close();

					}

					if (Mat1.Getdimension() != Mat2.Getdimension()) {
						error = -3;
						continue;
					}

					else if (piece3 == "+") {
						outfile << (Mat1 + Mat2).toString() << std::endl;
					}

					else if (piece3 == "-") {
						outfile << (Mat1 - Mat2).toString() << std::endl;
					}

					else if (piece3 == "*") {
						outfile << (Mat1 * Mat2).toString() << std::endl;
					}
				}
				}
							else if (check[1] == 0) {
							std::string piece = "";
							std::string piece_ = "";
							int Tr = 0;
							for (int i = 0; !ss2.eof(); i++) {
								ss2 >> piece;
								if (piece[0] == 'M') {
									if (piece_[0] == 'T') {
										Tr = 1;
									}
									break;
								}
								piece_ = piece;
							}
							if ((error = No_square(piece)) != 1)
								continue;
							MyMatrix<long long> Mat2(MakeMyMatlong(piece));
							if ((error = digonal(Mat2)) != 1)
								continue;

							if (Tr == 1)
								Mat2.transpose();
							Tr = 0;

							if (check[2] == 1) {
								std::string piece = "";
								std::string piece_ = "";
								int Tr = 0;
								for (int i = 0; !ss2.eof(); i++) {
									ss2 >> piece;
									if (piece[0] == 'M') {
										if (piece_[0] == 'T') {
											Tr = 1;
										}
										break;
									}
									piece_ = piece;
								}
								if ((error = No_square(piece)) != 1)
									continue;
								MyMatrix<int> Mat3(MakeMyMatint(piece));
								if ((error = digonal(Mat3)) != 1)
									continue;

								if (Tr == 1)
									Mat3.transpose();
								Tr = 0;


								if (count == 1) {
									outfile << Mat1.toString() << std::endl;
								}

								if (count == 2) {

									std::stringstream ss2(newcommand);
									for (int i = 0; i < 4; i++) {
										ss2 >> piece5;
										if (i == 0) {
											piece4 = piece5;
										}
										if (i == 1) {
											piece3 = piece5;
										}
									}

									if (piece3 == "=") {
										M.open(piece4 + ".txt");
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << Mat2.Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << Mat2.toString() << std::endl;
										M.close();

									}

									if (Mat1.Getdimension() != Mat2.Getdimension()) {
										error = -3;
										continue;
									}

									else if (piece3 == "+") {
										outfile << (Mat1 + Mat2).toString() << std::endl;
									}

									else if (piece3 == "-") {
										outfile << (Mat1 - Mat2).toString() << std::endl;
									}

									else if (piece3 == "*") {
										outfile << (Mat1 * Mat2).toString() << std::endl;
									}
								}

								if (count == 3) {
									std::stringstream ss2(newcommand);
									for (int i = 0; i < 4; i++) {
										ss2 >> piece6;
										if (i == 0) {
											piece7 = piece6;
										}
									}

									if (Mat2.Getdimension() != Mat3.Getdimension()) {
										error = -3;
										continue;
									}

									M.open(piece7 + ".txt");

									if (piece6 == "+") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 + Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 + Mat3).toString() << std::endl;
									}

									else if (piece6 == "-") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 - Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 - Mat3).toString() << std::endl;
									}

									else if (piece6 == "*") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 * Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 * Mat3).toString() << std::endl;
									}
									M.close();
								}
							}
							else if (check[2] == 0) {
								std::string piece = "";
								std::string piece_ = "";
								int Tr = 0;
								for (int i = 0; !ss2.eof(); i++) {
									ss2 >> piece;
									if (piece[0] == 'M') {
										if (piece_[0] == 'T') {
											Tr = 1;
										}
										break;
									}
									piece_ = piece;
								}
								if ((error = No_square(piece)) != 1)
									continue;
								MyMatrix<long long> Mat3(MakeMyMatlong(piece));
								if ((error = digonal(Mat3)) != 1)
									continue;

								if (Tr == 1)
									Mat3.transpose();
								Tr = 0;


								if (count == 1) {
									outfile << Mat1.toString() << std::endl;
								}

								if (count == 2) {

									std::stringstream ss2(newcommand);
									for (int i = 0; i < 4; i++) {
										ss2 >> piece5;
										if (i == 0) {
											piece4 = piece5;
										}
										if (i == 1) {
											piece3 = piece5;
										}
									}

									if (piece3 == "=") {
										M.open(piece4 + ".txt");
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << Mat2.Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << Mat2.toString() << std::endl;
										M.close();

									}

									if (Mat1.Getdimension() != Mat2.Getdimension()) {
										error = -3;
										continue;
									}

									else if (piece3 == "+") {
										outfile << (Mat1 + Mat2).toString() << std::endl;
									}

									else if (piece3 == "-") {
										outfile << (Mat1 - Mat2).toString() << std::endl;
									}

									else if (piece3 == "*") {
										outfile << (Mat1 * Mat2).toString() << std::endl;
									}
								}

								if (count == 3) {
									std::stringstream ss2(newcommand);
									for (int i = 0; i < 4; i++) {
										ss2 >> piece6;
										if (i == 0) {
											piece7 = piece6;
										}
									}

									if (Mat2.Getdimension() != Mat3.Getdimension()) {
										error = -3;
										continue;
									}

									M.open(piece7 + ".txt");

									if (piece6 == "+") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 + Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 + Mat3).toString() << std::endl;
									}

									else if (piece6 == "-") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 - Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 - Mat3).toString() << std::endl;
									}

									else if (piece6 == "*") {
										for (int i = 0; i < Mat2.Getdimension(); i++) {
											for (int j = 0; j < Mat2.Getdimension(); j++) {
												M << (Mat2 * Mat3).Getvector()[i][j];
												if (j != Mat2.Getdimension() - 1)
													M << " ";
											}
											if (i != Mat2.Getdimension() - 1)
												M << std::endl;
										}
										outfile << (Mat2 * Mat3).toString() << std::endl;
									}
									M.close();
								}
							}


							if (count == 1) {
								outfile << Mat1.toString() << std::endl;
							}

							if (count == 2) {

								std::stringstream ss2(newcommand);
								for (int i = 0; i < 4; i++) {
									ss2 >> piece5;
									if (i == 0) {
										piece4 = piece5;
									}
									if (i == 1) {
										piece3 = piece5;
									}
								}

								if (piece3 == "=") {
									M.open(piece4 + ".txt");
									for (int i = 0; i < Mat2.Getdimension(); i++) {
										for (int j = 0; j < Mat2.Getdimension(); j++) {
											M << Mat2.Getvector()[i][j];
											if (j != Mat2.Getdimension() - 1)
												M << " ";
										}
										if (i != Mat2.Getdimension() - 1)
											M << std::endl;
									}
									outfile << Mat2.toString() << std::endl;
									M.close();

								}

								if (Mat1.Getdimension() != Mat2.Getdimension()) {
									error = -3;
									continue;
								}

								else if (piece3 == "+") {
									outfile << (Mat1 + Mat2).toString() << std::endl;
								}

								else if (piece3 == "-") {
									outfile << (Mat1 - Mat2).toString() << std::endl;
								}

								else if (piece3 == "*") {
									outfile << (Mat1 * Mat2).toString() << std::endl;
								}
							}
			}

			if (count == 1) {
				outfile << Mat1.toString() << std::endl;
			}
			}	
}
if (error == 0)
outfile << "LOST_ELEMENT" << std::endl;
if (error == -1)
outfile << "NOT_SQUARE" << std::endl;
if (error == -2)
outfile << "NO_SQUARE" << std::endl;
		infile.close();
		outfile.close();
	};




std::vector<std::vector<int>> MakeMyMatint(std::string M_) {
	std::string row;
	std::ifstream M;
	M_ = M_ + ".txt";
	M.open(M_);
	std::string piece;
	long long element;

		std::vector<std::vector<int>> v;
		for (int i = 0; !M.eof(); i++) {

			getline(M, row);
			std::stringstream ss(row);
			std::vector<int> temp;

			for (int i = 0; !ss.eof(); i++) {
				ss >> piece;
				element = stoi(piece);
				temp.push_back(element);
			}
			v.push_back(temp);
		}
		return v;
}


std::vector<std::vector<long long>> MakeMyMatlong(std::string M_) {
	std::string row;
	std::ifstream M;
	M_ = M_ + ".txt";
	M.open(M_);
	std::string piece;
	long long element;


	std::vector<std::vector<long long>> v;
	for (int i = 0; !M.eof(); i++) {

		getline(M, row);
		std::stringstream ss(row);
		std::vector<long long> temp;

		for (int i = 0; !ss.eof(); i++) {
			ss >> piece;
			element = stoll(piece);
			temp.push_back(element);
		}
		v.push_back(temp);
	}
	return v;
}


int check_int(std::string M) {
	std::string M_ = M + ".txt";
	std::ifstream Mat;
	long long check;
	int key = 1;
	
	Mat.open(M_);
	Mat >> check;
	if (check > INT_MAX) {
		key = 0;
	}
	else
		key = 1;

	Mat.close();
	return key;
}

template <typename T>
int digonal(MyMatrix<T> a) {
	int k = a.Getvector().size();
	if (a.Getvector().size() == 1 && a.Getvector()[0].size()==1)
		return 1;
	for (int i= 0; i < a.Getvector().size()-1; i++){
		if(a.Getvector()[i].size()!=a.Getvector()[i+1].size())
			return 0;
	}

	if (a.Getvector()[0].size() != a.Getvector().size())
		return -1;

	return 1;
}

int No_square(std::string str) {
	std::ifstream infile;
	std::string s = str + ".txt";
	infile.open(s);
	if (infile.good())
		return 1;
	else
		return -2;
}



