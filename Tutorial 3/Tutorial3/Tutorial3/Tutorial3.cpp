
#include <iostream>
using namespace std;

bool myFunction(int x) {
	bool test;

	if (x >= 0) {
		test = true;
	}
	else {
		test = false;
	}
	return test;
}

void myLoop() {
	int z;
	do {
		cout << "Please enter a number" << endl;
		cin >> z;
	} while (z >= 0);
	cout << "Broke out";
}

int facSum(int p, int cfac) {
	int fac = cfac;
	int count = p;

	if (count > 0) {
		fac = fac + count;
		count--;
		
		cout << "Loop Again\n";
		cout << fac << endl;
		facSum(count, fac);
	}
	else{
	cout << "Break out\n";
	return fac;
	}
	
}

int main()
{
	int y;
	cout << "Please insert a number" << endl;
	cin >> y;
	cout << myFunction(y);
	cout << myFunction(-2);
	cout << myFunction(5) << endl;

	myLoop();

	cout << "Ex 3\n";
	int s;
	cout << "Please enter a number above 0\n";
	cin >> s;
	facSum(s, 0);
}


