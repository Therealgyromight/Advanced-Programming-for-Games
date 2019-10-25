
#include <iomanip> 
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <math.h>
//Done by Rui Antunes, 24/10/2019, ruizinho.antunes@gmail.com
using namespace std;
#include "PuzzleGen.h"
//--------------------------------------------------------------------------------------------------------------------------
PuzzleGen::PuzzleGen(int x, int y) {
	siz = x * x;
	min = y;
	max = (x * x) + x;
	row = x;
	
}
//--------------------------------------------------------------------------------------------------------------------------
PuzzleGen::~PuzzleGen() {

}
//--------------------------------------------------------------------------------------------------------------------------
int randRange(int low, int high) {
	return rand() % (high - low) + low;
}
//--------------------------------------------------------------------------------------------------------------------------
int PuzzleGen::isRepeated(int _value, vector<int> board) {
	auto it = find(board.begin(), board.end(), _value);
	if (it != board.end()) {
		cerr << "";
		return 1;
	}
	return 0;
}
//--------------------------------------------------------------------------------------------------------------------------
void PuzzleGen::InputGen() {
	
	ofstream myfile("InputFile.txt");
	myfile << 1 << endl;
		cout << "Please insert numbers from 1 to " << max << endl;

		vector<int> board;
		bool isNum;
		for (int r = 0; r < siz; r++) {
			if (r == siz - 1) {
				board.push_back(0);
				myfile << 0;
			}
			else {
				
					int value;
					do {
						cin >> value;
						if (!cin) {
							cout << "\nInput not valid. ";
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							isNum = false;
						}
						else
							isNum = true;
					} while (!isNum || (value > max || value < 1));
					
					
					
					if (isRepeated(value, board) == 1) {
						cout << "Repeated number";
						r--;
						continue;
					}
					else {
						if (r == max - 1) {

						}
						else {
							board.push_back(value);
							myfile << board[r] << ' ';
							if ((r + 1) % row == 0) { myfile << endl; }

							cout << board[r] << " was introduced in the board\n";


						}

					}
				
			}
		}
		myfile << endl;
		myfile << endl;
		myfile.close();
		
	}
	
//--------------------------------------------------------------------------------------------------------------------------

void PuzzleGen::AutoGen() {
	int puzNum;
	vector<int> board;
	ofstream myfile("InputFile.txt");
	cout << "Please enter the number of puzzles to generate" << endl;
	cin >> puzNum;
	myfile << puzNum;
	myfile << endl;
	
	srand(time(NULL));
	for (int ammount = 0; ammount < puzNum; ammount++) {
		
		for (int r = 0; r < siz; r++) {
			int p = randRange(1, max);
			if (isRepeated(p, board)) {
				r--;
				continue;
			}
			else {
				if (r == siz - 1) {
					board.push_back(0);
					myfile << 0;
				}
				else {
					board.push_back(p);
					myfile << board[r] << ' ';
					if((r + 1) % row == 0){myfile<<endl;}
				}
			}
		}

		myfile << endl;
		board.clear();
		myfile << endl;
	}
	myfile.close();
	
}


