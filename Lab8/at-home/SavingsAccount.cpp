// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include "Account.h"
#include "SavingsAccount.h"
#include <iomanip>
using namespace std;
namespace sict {

	SavingsAccount::SavingsAccount(double iBalance, double interest) : Account(iBalance){
		interest > 0 ? rate = interest : rate = 0.0;
	}

	void SavingsAccount::monthEnd() {
		double iEarned = balance() * rate;
		credit(iEarned);
	}

	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << endl;
		os.unsetf(std::ios::floatfield);
		os.precision(2);
		os.setf(std::ios::fixed, std::ios::floatfield);
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << rate * 100 << endl;
	}
}