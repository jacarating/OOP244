// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////
// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include "ChequingAccount.h"
#include <iomanip>
using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double fee, double month) : Account(balance){
		fee > 0 ? transFee = fee : transFee = 0.0;
		month > 0 ? monthlyFee = month : monthlyFee = 0.0;
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amount) {
		Account::debit(transFee);
		return Account::credit(amount);
	}


	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double amount) {
		Account::debit(transFee);
		return Account::debit(amount);
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		Account::debit(monthlyFee);
	}


	// display inserts account information into ostream os
	//

	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << endl;
		os.precision(2);
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << transFee << endl;
		os << "Monthly Fee: " << monthlyFee << endl;
	}



}