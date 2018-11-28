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

void read(sict:: Kingdom&);

int main() {
	int count = 0; 

	Kingdom* pKingdom = nullptr;

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	
	pKingdom = new Kingdom[count]; // Giving the pointer pKingdom allocated memory for "count" size.

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl; // Display the Kingdom number (iteration +1)
		
		Kingdom &xKingdom = pKingdom[i]; // Assign &xKingdom to the corresponding pKingdom[i] iteration.
		read(xKingdom); // Call the read function, and send the xKingdom variable.
	}
	cout << "==========" << endl << endl;
    
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
    sict:: display(pKingdom[0]); // call sict:: display(); here
	cout << "------------------------------" << endl << endl;
   
    
    Kingdom *p2Kingdom = nullptr; // allocate dynamic memory for count + 1 Kingdoms
    p2Kingdom = new Kingdom[count+1];   // expand the array of Kingdoms by 1 element
    
    for (int i = 0; i < count; i++){ // copy elements from original array into this newly allocated array
        p2Kingdom[i] = pKingdom[i];
    }
    
    delete[] pKingdom;  // Deallocated the memory that the corresponding new[] operator had allocated.
    pKingdom = p2Kingdom;	//copy the address of the newly allocated array into pKingdom pointer
    
    // add the new Kingdom
    cout << "==========\n"
    << "Input data\n"
    << "==========\n"
    << "Kingdom #" << count + 1 << ": " << endl;


	Kingdom &Kingdom2 = pKingdom[count];	// New variable that holds the value of pointer pKingdom
	read(Kingdom2);	// Call read function and send new variable. 
	count++;	// increment count by 1
	cout << "==========\n" << endl;
    
    // testing that the overload of "display(...)" works
    display(pKingdom, count);
    cout << endl;
	
	delete[] pKingdom; // Deallocated the memory that the corresponding new[] operator had allocated.
	pKingdom = nullptr;		// Reset the pKingdom pointer.
	return 0;
}

// accept data input from user.
void read(Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
