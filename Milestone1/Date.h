// Final Project Milestone 1
//
// Version 1.0
// Date
// Author Jacob Carating
// Description
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#include <istream>
namespace aid {
#define NO_ERROR 0 // No error - the date is valid
#define CIN_FAILED 1 // istream failed on information entry
#define DAY_ERROR 2 // Day value is invalid
#define MON_ERROR 3 // Month value is invalid
#define YEAR_ERROR 4 // Year value is invalid
#define PAST_ERROR 5 // Date value is invalid
	const int min_year = 2018;
	const int max_year = 2038;
	const int min_date = 751098;
	class Date {
		int current_year;
		int current_month;
		int current_day;
		int compare;
		int error;
		int mdays(int, int)const;
		void errCode(int errorCode);

	public:
		Date();
		Date(int year, int month, int day);
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		//void errCode(int errorValue);
		bool bad() const;
		bool isEmpty() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};

	std::ostream& operator<<(std::ostream&, Date&);
	std::istream& operator>>(std::istream&, Date&);




}
#endif
