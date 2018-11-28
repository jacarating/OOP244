// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"
#include <iostream>
namespace sict {
	class SavingsAccount : public Account {
		double rate;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};

}
#endif // !SICT_SAVINGSACCOUNT_H
