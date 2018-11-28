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
				*ccode = countryCode; //pointer will equal country code
				*acode = areaCode; // this pointer will equal area code
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
		numbers = nullptr;  // long long array
		size = 0;		// Number of valid phone numbers
	}

	Contact::Contact(const char *pName, const long long *pNumbers, int psize) {
		if (pName != nullptr || pName[0] != '\0') {
			strncpy(name, pName, MAX_CHAR);
			name[MAX_CHAR] = '\0';
			size = 0;

			if (pNumbers != nullptr) {
				numbers = new long long[psize];

				for (int i = 0; i < psize; i++) {
					if (validNum(pNumbers[i])) {
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
		return name[0] == '\0';
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

	Contact::Contact(const Contact& source) { // copy old object into new
		numbers = nullptr;
			*this = source; // this will call overloaded operator
		
	}

	Contact& Contact::operator=(const Contact& rhs) { // copy old object into existing object
		if (this != &rhs) {
			strcpy(name, rhs.name); // shallow copy
			size = rhs.size;
			delete[] numbers; // ensure array is empty
			if (rhs.numbers != nullptr) {
				numbers = new long long[size];
				for (int i = 0; i < size; i++) {
					numbers[i] = rhs.numbers[i];
				}
			}
			else
				numbers = nullptr;
			
		}
		return *this;
	}

	Contact& Contact::operator+=(long long pNumbers) {
		bool result = validNum(pNumbers);
		if (result){
			size++;
			long long * tNumbers = new long long [size];
			for (int i = 0; i < size -1 ; i++) { // - 1 because 
				tNumbers[i] = numbers[i];
			}
			tNumbers[size - 1] = pNumbers;
			delete[] numbers;
			numbers = tNumbers;
			
		}
		return *this;
	}
}
