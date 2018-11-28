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
			//int size = strlen(tName);
			strcpy(name, tName);
			health = tHealth;
			attack = tAttack;
		}
		else
			Hero();
	}

	void Hero::operator-=(int tAttack) {
		//bool validAttack = tAttack > 0;
		//if (validAttack) {
		//	health -= tAttack;
		//	if (health < 0) {
		//		health = 0;
		//	}
		//}
		tAttack > 0 ? health -= tAttack : health -= 0;
		health < 0 ? health = 0 : health;
	}

	bool Hero::isAlive() const {
		//bool result;
		//if (health > 0) {
		//	result = true;
		//}
		//else
		//	result = false;
		//return result;
		return health > 0;
	}

	int Hero::attackStrength() const {
		//bool validAttack = attack > 0;
		//int result;
		//if (validAttack) {
		//	result = validAttack;
		//}
		//else
		//	result = 0;
		//return result;
		return attack > 0 ? attack : 0;
	}

	//bool Hero::isEmpty() const{
	//	return name[0] != '\0' && attack > 0 && health > 0;
	//}
	std::ostream& operator<<(std::ostream& os, const Hero& hero) {
		bool isEmpty = hero.name[0] == '\0' && hero.attack == 0 && hero.health == 0;
		if (!isEmpty) {
			os << hero.name;
		}
		else
			cout << "No hero" << endl;

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
		for (int i = 1; i < MAX_ROUNDS && flag == 0; i++) {
			tFirst.operator-=(tSecond.attackStrength());
			tSecond.operator-=(tFirst.attackStrength());
			round++;
			if (!tFirst.isAlive() || !tSecond.isAlive()) { // If either hero is dead, stop the loop.
				flag = 1;
			}
		}
		const Hero* winner = tFirst.getHealth() >= tSecond.getHealth() ? &first : &second;
		cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << *winner << " in " << round << " rounds." << endl;;
		return *winner;
	}
}