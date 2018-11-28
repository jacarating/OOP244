// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict {

	bool Contact::validNum(const long long pNumbers, int* ccode = nullptr, int* acode = nullptr, int* a = nullptr, int* b = nullptr) const {

		bool result = false;

		if (pNumbers > 10000000000 && pNumbers <= 999999999999) {
			long long tNumbers = pNumbers;
			int countryCode = tNumbers / 10000000000; // Get country code
			tNumbers = tNumbers % 10000000000;
			int areaCode = tNumbers / 10000000; // Get area code
			tNumbers = tNumbers % 10000000;

			if (ccode != nullptr && acode != nullptr && a != nullptr && b != nullptr) {
				*ccode = countryCode;
				*acode = areaCode;
				*a = tNumbers / 10000;
				*b = tNumbers % 10000;
			}

			bool validArea = areaCode >= 100 && areaCode <= 999;
			bool validCountry = countryCode >= 1 && countryCode <= 99;

			if (validArea && validCountry && tNumbers > 1000000) { // check if valid
				result = true;
			}
		}
		return result;
	}

	Contact::Contact() {
		name[0] = '\0';
		numbers = nullptr;
		size = 0;
	}

	Contact::Contact(const char *pName, const long long *pNumbers, int psize) {

		if (pName != nullptr && pName[0] != '\0') {
			strncpy(name, pName, MAX_CHAR);
			name[MAX_CHAR] = '\0';
			size = 0;

			if (pNumbers != nullptr) {
				numbers = new long long[psize];

				for (int i = 0; i < psize; i++) {
					if (validNum(pNumbers[i]) == true) {
						numbers[size] = pNumbers[i];
						size++;
					}
				}
			}
			else {
				numbers = nullptr;
			}
		}
		else {
			*this = Contact();
		}
	}

	Contact::~Contact() {
		delete[] numbers;
	}

	bool Contact::isEmpty() const {
		return name[0] == '\0' && size == 0 && numbers == nullptr;
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << name << endl;
			for (int i = 0; i < size; i++) {
				int ccode;
				int acode;
				int a;
				int b;
				long long temp = numbers[i];
				validNum(temp, &ccode, &acode, &a, &b);
				cout << "(+" << ccode << ") " << acode << " " << a << "-";
				cout.fill('0');
				cout.width(4);
				cout << b << endl;
			}
		}
	}
}
