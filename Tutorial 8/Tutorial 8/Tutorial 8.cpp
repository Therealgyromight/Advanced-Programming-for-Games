// Tutorial 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void arrprint(char* inter, const int size) {
	for (int i = 0; i < size; i++) {
		cout << inter[i];
		
	}
}

void batalha() {
	int m;
	int n;
	int guesses = 10;
	bool battleship[5][5] = {
							{ false,false,false,true,true},
							{ false,false,false,false,false},
							{ false,false,true,false,false},
							{ true,false,true,false,false},
							{ true,false,true,false,false},
	};
	do {
		cout << "Please choose a grid position [0-4]" << endl;
		cin >> m;
		cout << "Please choose another grid position [0-4]" << endl;
		cin >> n;
		guesses--;
		if (battleship[m][n] == false) {
			cout << "Missed" << endl;
		}
		else
		{
			cout << "Sunk a ship" << endl;
			battleship[m][n] = false;
		}
		cout << "You have " << guesses << " attempts left" << endl;
	}
	while (guesses > 0);

			
}



int main()
{
	const int _size = 27;
	char arr[_size]={ 'r','u','i',' ','m','i','g','u','e','l',' ','f','e','r','r','e','i','r','a',' ','a','n','t','u','n','e','s'};
	char* inter = arr;
	arrprint(inter, _size);
	const int size1 = 3;
	const int size2 = 7;
	cout << endl;
	char* p = new char [size1] ;
	char* i = new char [size2] ;

	p[0] = arr[0];
	p[1] = arr[1];
	p[2] = arr[2];

	i[0] = arr[20];
	i[1] = arr[21];
	i[2] = arr[22];
	i[3] = arr[23];
	i[4] = arr[24];
	i[5] = arr[25];
	i[6] = arr[26];

	for (int l = 0; l < size1; l++) {
		cout << p[l];
	}

	cout << endl;

	for (int j = 0; j < size2; j++) {
		cout << i[j];
	}

	cout << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Welcome to the Battleship Game" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	batalha();
	
}



