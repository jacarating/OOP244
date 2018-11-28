// Student: Jacob Carating
// ID: 157 157 725
// Email: jacarating@myseneca.ca


#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict {


	Passenger::Passenger() {
		passName[0] = '\0';
		passDest[0] = '\0';
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *Name, const char *dest) {
		if (Name == nullptr || dest == nullptr) {
			*this = Passenger(); // The value of this object, set to an empty state
		}
		else {
			strncpy(passName, Name, LIMIT);
			strcpy(passDest, dest);
			passName[LIMIT - 1] = '\0'; // Set the last index of the array to the null byte.
		}
	}
	
	bool Passenger::isEmpty() const {
		bool result = strlen(passName) > 0 && strlen(passDest) > 0; // If the string has a length greater than 0, it is not empty.
		return !result;
	}

	void Passenger::display() const {
		if (!isEmpty()) {
			cout << passName << " - " << passDest << endl;
		}
		else
			cout << "No passenger!" << endl;
	}
}