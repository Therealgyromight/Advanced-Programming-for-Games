// CourseWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------------------------------------------------------------------------------------------------------
int board[4][4] = {0};
ofstream outputFile("Output_File.txt");
bool isRepeated(int value, int* board);
//--------------------------------------------------------------------------------------------------------------------------
void populate_board(int board[4][4]) {
	cout << "Please insert 15 numbers from 1 to 20" << endl;

	for (int r = 0; r < 4; r++) {
		if (board[3][2] == 0) {
			for (int c = 0; c < 4; c++) {
				if (board[3][2] == 0) {
					int value;
					cin >> value;
					if (value < 0 || value > 20) {
						cout << "Please enter a number from 1 to 20" << endl;
						
					}
					if (isRepeated(value, *board)) {
						cout << "Repeated number";
						c--;
						continue;
					}
					else {
						board[r][c] = value;
						cout << board[r][c] << "was introduced in the board\n";
					}
					
				}
				else {
					break;
				}
			}
		}
		else {
			break;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------
void generate_permutations() {
	
}
//--------------------------------------------------------------------------------------------------------------------------
int check_continuous() {
	int cc = 0;
	int rcc = 0;
	int cr = 0;
	int rcr = 0;
	for (int r = 0; r < 4; r++) {
		if (board[r][0] + 1 == board[r][1] && board[r][1] + 1 == board[r][2] && board[r][2] + 1 == board[r][3]) {
			cout << "Row is continuous\n";
			cr++;
		}
		if (board[r][3] - 1 == board[r][2] && board[r][2] - 1 == board[r][1] && board[r][1] - 1 == board[r][0]) {
			cout << "Row is reverse continuous\n";
			rcr++;
		}
	}
	for (int c = 0; c < 4; c++) {
		if (board[0][c] + 1 == board[1][c] && board[1][c] + 1 == board[2][c] && board[2][c] + 1 == board[3][c]) {
			cout << "Column is continuous\n";
			cc++;
		}
		if (board[3][c] - 1 == board[2][c] && board[2][c] - 1 == board[1][c] && board[1][c] - 1 == board[0][c]) {
			cout << "Column is reverse continuous\n";
			rcc++;
		}
	}
	int comb = cc + rcc + cr + rcr;
	return comb;
}
//--------------------------------------------------------------------------------------------------------------------------

void print_board() {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			cout << board[r][c] << ' ';
			outputFile << board[r][c] << ' ';
		}
		cout << endl;
		outputFile << endl;
	}
}
//--------------------------------------------------------------------------------------------------------------------------
bool isRepeated(int _value, int* board) {
	for (int r = 0; r < 4; r++) {
		for (int c = 0; c < 4; c++) {
			if (_value == *(board+r*c+c)){
				cout << "The number " << _value << " already exists" << endl;
				return true;
			}
		}
	}
	return false;
}
//--------------------------------------------------------------------------------------------------------------------------
int main()
{
	populate_board(board);
	print_board();
	cout << check_continuous() << endl;
}

//--------------------------------------------------------------------------------------------------------------------------
