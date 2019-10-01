// Tutorial2Exercices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
using namespace std;

void add(int a, int b);


double Events(std::function <double(double, int)> EventType, double x, int y) {
	return EventType(x, y);
}


int main()
{
    std::cout << "Hello World!\n";
	int a = 5;
	int b = 4;
	int d;
	double c, f;
	char op;
	

	cout << a * b << endl;

	std::function<double(double, int)> quotient = [](double x, int y) {
		return x / y;
	};

	std::function<double(double, int)> sum = [](double x, int y) {
		return x + y;
	};

	std::function<double(double, int)> difference = [](double x, int y) {
		return x - y;
	};

	std::function<double(double, int)> product = [](double x, int y) {
		return x * y;
	};

	cout << Events(quotient, 5, 3) << endl;


	cout << "Enter the first number" << endl;
	cin >> c;

	cout << "Enter the second number" << endl;
	cin >> d;

	cout << "Choose an operation (+, -, * or /)" << endl;
	cin >> op;

	switch (op) {
	case '/':
		cout << Events(quotient, c, d) << endl;
		break;

	case '+':
		cout << Events(sum, c, d) << endl;
		break;

	case '-':
		cout << Events(difference, c, d) << endl;
		break;

	case '*':
		cout << Events(product, c, d) << endl;
		break;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
