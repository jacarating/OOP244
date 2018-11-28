/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
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
namespace sict {
    
	void display(const Kingdom &King) { 
        cout << King.m_name << ", population " << King.m_population << endl;		// Display one instance of the data recieved 
		
	}
    
    void display(Kingdom const King[], int size) { 

        cout << "------------------------------" << endl;	// Formatting..
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;

		int sum = 0;			// Initialized totalpop to 0.

        for (int i = 0; i <size; i++){
			cout << i + 1 << ". "; // For every iteration, display the values for the corresponding King[i] iteration.
			display(King[i]);		// Call display function and send the King array of iteration i.
			sum += King[i].m_population;	// Add each Kingdom population to the current iteration of i.
        }
        
        cout << "------------------------------" << endl;
        cout<< "Total population of SICT: "<< sum << endl;
        cout << "------------------------------" << endl;
    }
}
