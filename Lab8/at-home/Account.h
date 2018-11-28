// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"
namespace sict {
	class Account : public iAccount{
		double cBalance;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};


}
#endif // !SICT_ACCOUNT_H