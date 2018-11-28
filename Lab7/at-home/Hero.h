// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#ifndef _HERO_H
#define _HERO_H
#include <iostream>
namespace sict {
#define MAX_ROUNDS 100
	class Hero {
	//protected:
		char name[40 + 1];
		int health;
		int attack;
	public:
		Hero();
		Hero(const char * tName, int tHealth, int tAttack);
		void operator-=(int tAttack);
		bool isAlive() const;
		int getHealth() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif // !_HERO_H
