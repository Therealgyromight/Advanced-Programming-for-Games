// Tutorial4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

void swap(int b, int l, int f, int g) {
	
	b = l;
	f = g;
	cout << b << "and" << f << endl;
}

void arrayfunc(int* j) {
	for (int x = 0; x < 10; x++) {
		if (!(*(j + x) % 2)) cout << *(j + x);
	}
}

int main()
{
    //Because pointers dont work with half bytes.
	int x = 100;
	int y = 200;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = &x;
	
	cout << p << ' ' << p + 1 << endl;
	int* l = &y;
	int* a = arr;
	cout << x << "and" << y << endl;
	cout << &a << endl;
	cout << &a << ' ' << a << ' ' << (a + 1) << endl;
	swap(x, *l, y, *p);
	
	arrayfunc(a);
	cout << p << endl;
	cout << *p << endl;
	cout << &p << endl;
}


