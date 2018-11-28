// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#include "Account.h"
#include <iostream>
using namespace std;
namespace sict {
	Account::Account(double tBalance) {
		tBalance > 0 ? cBalance = tBalance : cBalance = 0.0;
	}

	bool Account::credit(double amount) {
		return amount > 0 ? cBalance += amount : false;
	}

	bool Account::debit(double amount) {
		return amount > 0 ? cBalance -= amount : false;
	}

	double Account::balance() const {
		return cBalance;
	}
}
