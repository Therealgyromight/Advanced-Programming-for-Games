// TestEnvironment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Creature {
public:
	Creature(int hp, int armor, int movement, int damage);
	~Creature();
	int get_hp() { return hps; }
	int get_armor() { return armors; }
	int get_movement() { return movements; }
	int get_damage() { return damages; }
	void set_hp(int x);
	void set_movement(int x);
	void set_armor(int x);
	void set_damage(int x);
protected:
	int hps;
	int armors;
	int movements;
	int damages;
};

Creature::Creature(int hp, int armor, int movement, int damage) {
	hps = hp;
	armors = armor;
	damages = damage;
	movements = movement;
}

Creature::~Creature() {
}

void Creature::set_hp(int x) {
	hps = x;
}

void Creature::set_armor(int x) {
	armors = x;
}

void Creature::set_damage(int x) {
	damages = x;
}

void Creature::set_movement(int x) {
	movements = x;
}

int main()
{
	Creature el (10, 5, 45, 20);
	
    std::cout << el.get_armor() << endl;

	el.set_armor(900);

	std::cout << el.get_armor();
}

