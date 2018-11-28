// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"
using namespace sict;

namespace sict {			
	class SuperHero : public Hero {
		int superPower;
		int defense;
	public:
		SuperHero();
		SuperHero(const char *, int, int, int, int);
		int attackStrength() const;
		int defend() const;
		bool isEmpty() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif // !SICT_SUPERHERO_H
