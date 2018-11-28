// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#include "SavingsAccount.h"
#include "ChequingAccount.h"
namespace sict {
	const double interestRate = 0.05;
	const double transacFee = 0.50;
	const double monthFee = 2.00;
	iAccount* CreateAccount(const char* type, double iBalance){
		bool Savings = type[0] == 'S';
		bool Chequing = type[0] == 'C';
		iAccount *newAccount = nullptr;
		if (Savings) {
			newAccount = new SavingsAccount(iBalance, interestRate);
		}
		if (Chequing) {
			newAccount = new ChequingAccount(iBalance, transacFee, monthFee);
		}
		return Savings || Chequing ? newAccount : nullptr;
	}
}
