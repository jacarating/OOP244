// Student: Jacob Carating
// ID: 157 157 725
// Email: jacarating@myseneca.ca




#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace sict {
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		if (sin < max_sin && sin > min_sin && familyName[0] != '\0' && givenName[0] != '\0') { // Check sin value & if empty.
			
			int copysin = sin;
			int sum = 0;

			for (int i = 0; i < 9; i++) {
				if (i % 2 == 0) {	// if there is no remainder, the element is even.
					sum += copysin % 10; // find the remainder of copysin and assign that value to sum.
				}
				else {
					int temp = (copysin % 10) * 2;  // find the remainder of copysin, multiply the number by 2. Assign to temp.
					sum += temp / 10 + temp % 10; // get the left(division) and right digit (modulus). Add their values to sum. 
				}
				copysin /= 10;	// After every iteration, divide copysin 10.
			}

			if (sum % 10 == 0) {
				strncpy(fam_name, familyName, max_name_length);
				fam_name[max_name_length] = '\0';
				strncpy(giv_name, givenName, max_name_length);
				giv_name[max_name_length] = '\0';
				SIN_Num = sin;
				for (int i = 0; i < max_yrs; i++) {
					taxReturn[i] = 0;	// Initialize to empty state.
				}
			}
			
		}
		else {
			SIN_Num = 0;
			strcpy(fam_name, "\0");
			strcpy(giv_name, "\0");

		}

	}

	bool CRA_Account::isEmpty() const {
		bool result;
		if (SIN_Num == 0) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}

	void CRA_Account::display() const {
		if (!isEmpty()) {
			cout << "Family Name: " << fam_name << endl;
			cout << "Given Name : " << giv_name << endl;
			cout << "CRA Account: " << SIN_Num << endl;
			for (int i = 0; i < max_yrs; i++) {

				if (money[i] > 2.00) {
					cout.setf(ios::fixed);
					cout.precision(2);
					cout << "Year (" << taxReturn[i] << ") balance owing: " << money[i] << endl;
				}
				else if (money[i] < -2.00) {
					cout << "Year (" << taxReturn[i] << ") refund due: " << -money[i] << endl;

				}
				else {
					cout << "Year (" << taxReturn[i] << ") No balance owing or refund due!" << endl;
				}

			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	void CRA_Account::set(int year, double balance) {
		if (!isEmpty()) {
			int flag = 0;
			for (int i = 0; i < max_yrs && flag == 0; i++) {
				if (!taxReturn[i]) {
					taxReturn[i] = year;
					money[i] = balance;
					flag = 1;
				}
			}
		}
	}


}
