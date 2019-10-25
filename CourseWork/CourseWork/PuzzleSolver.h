#pragma once
#include <vector>
#include <string>
//Done by Rui Antunes, 24/10/2019, ruizinho.antunes@gmail.com
using namespace std;
class PuzzleSolver
{
public:
	PuzzleSolver(int x);
	~PuzzleSolver();
	unsigned long long SolvePuzzle(int size, int oper);
	void sort(string x);
	void fileSolve();
	vector <unsigned int> vboard;
	int num;
protected:
	int combinations;
	int sizearray;
};

