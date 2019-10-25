// CourseWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PuzzleSolver.h"
#include "PuzzleGen.h"
#include <iomanip> 
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
//Done by Rui Antunes, 24/10/2019, ruizinho.antunes@gmail.com
using namespace std;
int sizeb = 1;
int main()
{
	int choice;
	int repeat = 0;
	int menu;
	int y = 1;
	string fName;
	string def = "InputFile.txt";
	do {
		do {
			cout << "Please choose what you would like to do:" << endl;
			cout << "1 : Generate x puzzles for me and calculate rows and columns" << endl;
			cout << "2 : Let me input a puzzle" << endl;
			cout << "3 : Read puzzles from a file" << endl;
			cin >> menu;
		} while (menu > 3 || menu < 1);
		cout << "Please enter size of puzzle" << endl;
		cin >> sizeb;
		PuzzleGen Obj(sizeb, y);
		PuzzleSolver Solver(sizeb);
		switch (menu) {
		case 1: 
			
			Obj.AutoGen();
			Solver.sort(def);
			do {
				cout << "Would you like to run the program again ? (Yes = 0; No = 1)" << endl;
				cin >> repeat;
			} while (repeat != 0 && repeat != 1);
			system("cls");
			break;
		case 2: 
			
			Obj.InputGen();
			Solver.sort(def);
			do {
				cout << "Would you like to run the program again ? (Yes = 0; No = 1)" << endl;
				cin >> repeat;
			} while (repeat != 0 && repeat != 1);
			system("cls");
			break;
		case 3:
			Solver.fileSolve();
			do {
				cout << "Would you like to run the program again ? (Yes = 0; No = 1)" << endl;
				cin >> repeat;
			} while (repeat != 0 && repeat != 1);
			system("cls");
			break;
		}
	} while (repeat == 0);

}









