// Student: Jacob Carating
// ID: 157 725 177
// Email: jacarating@myseneca.ca





#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H



#include <iostream>

using namespace std;

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;
	class CRA_Account {

		char fam_name[max_name_length + 1];
		char giv_name[max_name_length + 1];
		int SIN_Num;
		int taxReturn[max_yrs];
		float money[max_yrs];
		
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
		

	};
}

#endif 

