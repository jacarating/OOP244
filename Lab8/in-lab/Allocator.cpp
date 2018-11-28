// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca#
#include "SavingsAccount.h"
namespace sict {
	const double interestRate = 0.05;

	iAccount* CreateAccount(const char* type, double iBalance){
		iAccount *newAccount = nullptr;
		if (type[0] == 'S') {
			newAccount = new SavingsAccount(iBalance, interestRate);
		}
		return newAccount;
	}
}
