/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date 9/17/2018
// Author Jacob Carating
// Description
// ID: 157 725 177
// Email: jacarating@myseneca.ca
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; 

	Kingdom *pKingdom = nullptr;	// Set the pointer to be pointing to nothing.

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	pKingdom = new Kingdom[count]; // Giving the pointer pKingdom allocated memory for "count" size.


	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;	// Display the Kingdom number (iteration +1)
		Kingdom& xKingdom = pKingdom[i];	// Assign type Kingdom& to the corresponding pKingdom[i] iteration.
		read(xKingdom);						// Call the read function, and send the xKingdom variable.
	}
	cout << "==========" << endl << endl;

	
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	delete[] pKingdom;		// Deallocated the memory that the corresponding new[] operator had allocated.
	pKingdom = nullptr;		// Reset the pKingdom pointer.
	return 0;
}


void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
	
