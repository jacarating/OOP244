// Jacob Carating
// 157 715 177
// jacarating@myseneca.ca
#include "Perishable.h"
#include <iostream>
using namespace std;
namespace aid {

	Perishable::Perishable() : Good('P') {
		pDate = Date();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Good::store(file, false);
		file << ',';
		pDate.write(file);
		if (newLine == true) {
			file << endl;
		}
		return file;
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Good::load(file);
		file.ignore();
		pDate.read(file);
		file.ignore();
		return file;
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const{
		Good::write(os, linear);

		if (isClear() || !pDate.isEmpty()) {
			if (linear) {
				pDate.write(os);
			}
			else {
				os << '\n' << " Expiry date: ";
				pDate.write(os);
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Good::read(is);
		Date temp = Date();
		if (!is.fail()) {
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;

			if (temp.bad()) {
				if (temp.errCode() == CIN_FAILED) {
					Good::messages("Invalid Date Entry");
				}

				else if (temp.errCode() == YEAR_ERROR) {
					Good::messages("Invalid Year in Date Entry");
				}

				else if (temp.errCode() == MON_ERROR) {
					Good::messages("Invalid Month in Date Entry");
				}

				else if (temp.errCode() == DAY_ERROR) {
					Good::messages("Invalid Day in Date Entry");

				}

				else if (temp.errCode() == PAST_ERROR) {
					Good::messages("Invalid Expiry in Date Entry");
				}
				else { ;; }

				is.setstate(std::ios::failbit);

			}
			else { 
				pDate = temp; 
			}
		}
		return is;
	}
	const Date& Perishable::expiry() const {
		return pDate;
	}
}
