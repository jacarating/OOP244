// Student: Jacob Carating
// ID: 157 157 725
// Email: jacarating@myseneca.ca




#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {


	Passenger::Passenger() { // Default constructor
		passName[0] = '\0';
		passDest[0] = '\0';
		yoD = 0;
		moD = 0;
		doD = 0;
	}
	
	Passenger::Passenger(const char *Name, const char *dest) {
		if (Name == nullptr || dest == nullptr || Name[0] == '\0' || dest[0] == '\0') {
			*this = Passenger(); // The value of this object, set to an empty state
		}
		else {
			strncpy(passName, Name, LIMIT);
			strncpy(passDest, dest, LIMIT);
			passName[LIMIT - 1] = '\0'; // Set the last index of the array to the null byte.
			moD = 10;
			yoD = 2018;
			doD = 1;
		}
	}
	
	bool Passenger::isEmpty() const {
		bool result = strlen(passName) > 0 && strlen(passDest) > 0; // If either string has a length greater than 0, it is not empty.
		return !result;
	}

	void Passenger::display() const {
		if (!isEmpty()) {
			

			cout << passName << " - " << passDest << " on " << yoD << "/";
			cout.fill('0'); // Fill any leftover width with 0's.
			cout.width(2); // Set for two digits for next cout.
			cout << moD << "/";
			cout.width(2); // Set for two digits for next cout.
			cout << doD << endl;

		}
		else
			cout << "No passenger!" << endl;
	}

	Passenger::Passenger(const char *Name, const char *Des, const int year, const int month, const int day) {
	
		if (year >= 2018 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && Name != nullptr && Des != nullptr && Name[0] != '\0' && Des[0] != '\0') {
			strncpy(passName, Name, LIMIT);
			strcpy(passDest, Des);
			passName[LIMIT - 1] = '\0';
			yoD = year;
			moD = month;
			doD = day;
		}
		else {
			*this = Passenger();
		}

	}

	const char* Passenger::name() const {
		if (!isEmpty()) {
			return passName;
		}
		else {
			char *emptyString = nullptr;
			emptyString = new char[2];

			return emptyString;
		}
	}

	bool Passenger::canTravelWith(const Passenger &passenger2) const {
		bool result;
		if (strcmp(passenger2.passDest, passDest) == 0  && passenger2.doD == doD && passenger2.yoD == yoD && passenger2.moD == moD) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}
}