#pragma once
#include <vector>
#include <string>
//Done by Rui Antunes, 24/10/2019, ruizinho.antunes@gmail.com
using namespace std;
class PuzzleGen
{
public:
	PuzzleGen(int x, int y);
	~PuzzleGen();
	void InputGen();
	void AutoGen();
	int isRepeated(int _value, vector<int> board);
	
protected:
	int siz;
	int min;
	int max;
	int row;
};

