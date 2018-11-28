// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include "SuperHero.h"
#include "Hero.h"
#include <iostream>
#include <cstring>
using namespace std;
using namespace sict;

namespace sict {
	SuperHero::SuperHero() : Hero(){ // We don't need to initialize the other data members because the Hero() constructor is being called beforehand.
		superPower = 0;
		defense = 0;
	}

	SuperHero::SuperHero(const char* tName, int tHealth, int tAttack, int tSuperPower, int tDefense) : Hero(tName, tHealth, tAttack) {
		bool validSuperPower = tSuperPower > 0;
		bool validDefense = tDefense > 0;

		if (validSuperPower && validDefense) {
			superPower = tSuperPower;
			defense = tDefense;
		}
		else
			*this = SuperHero();
	}

	int SuperHero::attackStrength() const{
		return !isEmpty() && isAlive() ? Hero::attackStrength() + superPower : 0;
	}

	bool SuperHero::isEmpty() const {
		return isAlive() && superPower == 0 && defense == 0;
	}

	int SuperHero::defend() const {
		return !isEmpty() && isAlive() ? defense : 0;
	}

	const SuperHero& operator*(const SuperHero& tFirst, const SuperHero& tSecond) {
		int flag = 0;
		int round = 0;
		SuperHero First = tFirst;
		SuperHero Second = tSecond;
		const SuperHero * winner = &tFirst; // default winner
		for (int i = 1; i < MAX_ROUNDS && flag == 0; i++) { 
			First -= Second.attackStrength() - First.defend();
			Second -= First.attackStrength() - Second.defend();
			round++;
			if (!First.isAlive() || !Second.isAlive()) { // If either hero is dead, stop the loop.
				flag = 1;
			}
		}
		winner = tFirst.getHealth() >= tSecond.getHealth() ? &tFirst : &tSecond;
		cout << "Super Fight! " << tFirst << " vs " << tSecond << " : Winner is " << *winner << " in " << round << " rounds." << endl;
		return *winner;
	}

}
