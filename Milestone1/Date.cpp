// Final Project Milestone 1
//
// Version 1.0
// Date 10/23/2018
// Author	Jake Carating
// Jacarating@myseneca.ca
// 157 725 177
// Description  
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace aid {

	// number of days in month mon and year year
	//
	Date::Date() {
		current_day = 00;
		current_month = 00;
		current_year = 0000;
		compare = 0;
		errCode(NO_ERROR);
	}

	Date::Date(int year, int month, int day) {
		bool validYear = year >= min_year && year <= max_year;
		bool validMonth = month >= 1 && month <= 12;
		bool validDay = day >= 1 && day <= mdays(month, year);
		int tempComp = year * 372 + month * 31 + day;

		if (validDay && validMonth && validYear && tempComp >= min_date) {
			current_year = year;
			current_month = month;
			current_day = day;
			errCode(NO_ERROR);
			compare = year * 372 + month * 31 + day;
		}
		else {
			*this = Date();
			compare = 0;
		}


		if (validYear == false) {
			errCode(YEAR_ERROR);
		}

		else if (validMonth == false) {
			errCode(MON_ERROR);
		}

		else if (validDay == false) {
			errCode(DAY_ERROR);
		}

		else if (tempComp < min_date) {
			errCode(PAST_ERROR);
		}
	}

	bool Date::isEmpty() const {
		return current_day == 00 && current_month == 00 && current_year == 0000 && compare == 0;
	}

	bool Date::operator== (const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare == rhs.compare;
	}

	bool Date::operator!=(const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare != rhs.compare;
	}

	bool Date::operator<(const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare < rhs.compare;
	}

	bool Date::operator>(const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare > rhs.compare;
	}

	bool Date::operator<=(const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare <= rhs.compare;
	}

	bool Date::operator>=(const Date& rhs) const {
		return !isEmpty() && !rhs.isEmpty() && compare >= rhs.compare;
	}

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		error = errorCode;
	}

	int Date::errCode() const {
		return error;
	}

	bool Date::bad() const {
		bool result = false;
		if (error != NO_ERROR) {
			result = true;
		}
		return result;
	}


	std::istream& Date::read(std::istream& istr) {
		int tYear, tMonth, tDay;
		char delimeter;
		istr >> tYear >> delimeter >> tMonth >> delimeter >> tDay;
		if (istr.fail()) {
			*this = Date();
			error = CIN_FAILED;
		}
		else {
			*this = Date(tYear, tMonth, tDay);
			istr.clear();
		}
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << current_year << "/";
		ostr.fill('0');
		ostr.width(2);
		ostr << current_month << "/";
		ostr.width(2);
		ostr << current_day;
		return ostr;
	}

	std::ostream& operator<<(std::ostream& lhs, Date& rhs) {
		rhs.write(lhs);
		return lhs;
	}

	std::istream& operator>>(std::istream& lhs, Date& rhs) {
		rhs.read(lhs);
		return lhs;
	}
}
