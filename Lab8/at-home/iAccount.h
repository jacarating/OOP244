// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>

namespace sict {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() {};
	};

	iAccount* CreateAccount(const char*, double);

}
#endif // 