// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Hero.h"
#include <cstring>
using namespace std;
namespace sict {
	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack = 0;
	}

	Hero::Hero(const char * tName, int tHealth, int tAttack) {
		bool validName = tName[0] != '\0';
		bool validHealth = tHealth > 0;
		bool validAttack = tAttack > 0;

		if (validName && validAttack && validHealth) {
			strcpy(name, tName);
			health = tHealth;
			attack = tAttack;
		}
		else
			*this = Hero();
	}

	void Hero::operator-=(int tAttack) {
		tAttack > 0 ? health -= tAttack : health -= 0;
		health < 0 ? health = 0 : health;
	}

	bool Hero::isAlive() const {
		return health > 0;
	}

	int Hero::attackStrength() const {
		return attack > 0 ? attack : 0;
	}

	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		bool isEmpty = hero.name == nullptr || hero.name[0] == '\0';
		if (!isEmpty) {
			os << hero.name;
		}
		else
			os << "No hero";

		return os;
	}

	int Hero::getHealth() const {
		return health;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		int flag = 0;
		int round = 0;
		Hero tFirst = first;
		Hero tSecond = second;
		const Hero * winner = &first; // default winner is first hero.
		for (int i = 1; i < MAX_ROUNDS && flag == 0; i++) {
			tFirst.operator-=(tSecond.attackStrength());
			tSecond.operator-=(tFirst.attackStrength());
			round++;
			if (!tFirst.isAlive() || !tSecond.isAlive()) { // If either hero is dead, stop the loop.
				flag = 1;
			}
		}
		winner = tFirst.getHealth() >= tSecond.getHealth() ? &first : &second;
		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << round << " rounds." << endl;
		return *winner;
	}
}