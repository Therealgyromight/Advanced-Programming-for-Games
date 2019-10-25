#include "PuzzleSolver.h"
#include <iomanip> 
#include <iostream>
#include <fstream>
#include <limits>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <filesystem>

//Done by Rui Antunes, 24/10/2019, ruizinho.antunes@gmail.com
using namespace std;

//constructor
PuzzleSolver::PuzzleSolver(int x) {
	combinations = 0;
	num = 0;
	sizearray = x;
	vector<unsigned int> vboard;
}
//--------------------------------------------------------------------------------------------------------------------------
PuzzleSolver::~PuzzleSolver() {

}
//--------------------------------------------------------------------------------------------------------------------------
void PuzzleSolver::sort(string x) {

	ifstream mfile(x);
	ofstream ofile("OutputFile.txt");
	unsigned long long current2 = 0;
	unsigned long long current3 = 0;
	unsigned long long current4 = 0;


	
	
	mfile >> num;
	ofile << num << endl;
	cout << num << endl;
	//loop for number of boards
	for (int j = 0; j < num; j++) {
		vboard.clear();
		mfile.ignore(1000, '\n');
		if (j > 0) ofile << endl; cout << endl;
		for (int i = 0; i < sizearray; i++) {
			string str;
			if (getline(mfile, str)) {
				istringstream ss(str);
				int value;
				while (ss >> value) {
					vboard.push_back(value);
					
				}
			}
		}
		//reading from file into vector
		for (int r = 0; r < (sizearray * sizearray); r++) {
			if (r == (sizearray * sizearray) - 1) {
				ofile << 0 << endl;
				cout << setw(5) << 0 << endl;
			}
			else {
				ofile << vboard[r] << ' ';
				cout << setw(5) << vboard[r] << ' ';
				if ((r + 1) % sizearray == 0) { ofile << endl; cout << endl; }
			}
		}
		//Calling solves for the vectors and printing
		current2 = PuzzleSolver::SolvePuzzle(sizearray * sizearray, 6);
		current3 = PuzzleSolver::SolvePuzzle(sizearray * sizearray, 5);
		current4 = PuzzleSolver::SolvePuzzle(sizearray * sizearray, 4);
	std::sort(vboard.begin(), vboard.end() - 1);
	cout << "Number of Rows (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	ofile << "Number of Rows (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	cout << "Number of Reverse Rows (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	ofile << "Number of Reverse Rows (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	cout << "Number of Columns (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	ofile << "Number of Columns (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	cout << "Number of Reverse Columns (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	ofile << "Number of Reverse Columns (4) " << PuzzleSolver::SolvePuzzle(sizearray * sizearray,1) << endl;
	cout << "total for row and column including reverse for this configuration" << endl;
	ofile << "total for row and column including reverse for this configuration" << endl;
	cout << "2 = " << current2 << endl;
	cout << "3 = " << current3 << endl;
	cout << "4 = " << current4 << endl;
	ofile << "2 = " << current2 << endl;
	ofile << "3 = " << current3 << endl;
	ofile << "4 = " << current4 << endl;
	cout << "total for row and column including reverse for all possible and valid configuration" << endl;
	ofile << "total for row and column including reverse for all possible and valid configuration" << endl;
	cout << "2 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 3) << endl;
	cout << "3 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 2) << endl;
	cout << "4 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 1) << endl;
	ofile << "2 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 3) << endl;
	ofile << "3 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 2) << endl;
	ofile << "4 = " << PuzzleSolver::SolvePuzzle(sizearray * sizearray, 1) << endl;
	}	
	mfile.close();
	ofile.close();
}
//--------------------------------------------------------------------------------------------------------------------------
unsigned int factCalc(unsigned int f) {
	
	if (f > 1) {
		return f * factCalc(f - 1);
	}
	else {
		return 1;
	}
	
}
//--------------------------------------------------------------------------------------------------------------------------
//algorithm to calculate number of rows etc.
unsigned long long PuzzleSolver::SolvePuzzle(int size, int oper) {
	int _size = sqrt(size);
	unsigned long long controw3 = 0;
	unsigned long long controws = 0;
	unsigned long long controw2 = 0;
	switch (oper) {
	case 1:
		for (unsigned long long i = 0; i < ((size)-(3)); i++) {
			if (vboard[i] + (3) == vboard[i + (3)]) {
				controws += (((_size * ((_size - 4) + 1) - 1) * (factCalc((((size)-4) - 1)) / 2)));
			}
		}
		return controws;
		break;
	case 2:
		for (unsigned long long f = 0; f < ((size)-(2)); f++) {
			if (vboard[f] + 2 == vboard[f + 2]) {
				controw3 += (((_size * ((_size - 3) + 1) - 1) * (factCalc((((size)-3) - 1)) / 2)));
			}
		}
		return controw3;
		break;
	case 3:
		for (unsigned long long k = 0; k < ((size)-(1)); k++) {
			if (vboard[k] + 1 == vboard[k + 1]) {
				//number of rows * combos of 2 per row - 1 for 0 * factorial of the remaining spots not locked in the combination 
				//divided by 2 because only half the combinations are possible
				controw2 += (((_size * ((_size - 2) + 1) - 1) * (factCalc((((size)-2) - 1)) / 2)));
			}
		}
		return controw2;
		break;
	case 4:
		for (unsigned long long l = 0; l < ((size)-(3)); l++) {
			
			if (l < 3) {
				if (vboard[l] + 3 == vboard[l + 3] && vboard[l] + 2 == vboard[l + 2] && vboard[l] + 3 == vboard[l + 3]) {
					controws++;
				}
			}
			else {
				if (vboard[l] + 3 == vboard[l + 3] || vboard[l] - 3 == vboard[l - 3] && vboard[l] + 2 == vboard[l + 2] || vboard[l] - 2 == vboard[l - 2] && vboard[l] + 1 == vboard[l + 1] || vboard[l] - 1 == vboard[l - 1]) {

					controws++;
				}
			}
		}
		break;
	case 5:
		for (unsigned long long q = 0; q < ((size)-(2)); q++) {
			if (q < 2) {
				if (vboard[q] + 2 == vboard[q + 2] && vboard[q] + 1 == vboard[q + 1]) {
					controw3++;
				}
			}
			else {
				if ((vboard[q] + 2 == vboard[q + 2] && vboard[q] + 1 == vboard[q + 1]) || (vboard[q] - 2 == vboard[q - 2] && vboard[q] - 1 == vboard[q - 1])) {

					controw3++;
				}
			}
		}
		return controw3;
		break;
	case 6:
		for (unsigned long long a = 0; a < ((size)-(1)); a++) {
			if (a == 0) {
				if (vboard[a] + 1 == vboard[a + 1]) {
					controw2++;
				}
			}
			else {
				if (vboard[a] + 1 == vboard[a + 1] || vboard[a] - 1 == vboard[a - 1]) {

					controw2++;
				}
			}

		}
		return controw2;
		break;
		}

	}
//--------------------------------------------------------------------------------------------------------------------------
// check if file inserted exists
bool fileExists(const string& file) {
	struct stat buf;
	return (stat(file.c_str(), &buf) == 0);
}
//--------------------------------------------------------------------------------------------------------------------------
//load up the file to be solved
void PuzzleSolver::fileSolve() {
	string fName;
	do {
		cout << "Please enter the name of the files to read" << endl;
		cin >> fName;
	} while (!fileExists(fName));
	PuzzleSolver::sort(fName);
}





