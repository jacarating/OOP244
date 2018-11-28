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
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


#include <iostream>
using namespace std;		// Use the std scope.
#include "Kingdom.h"

namespace sict {
	void display(Kingdom& King) {
		cout << King.m_name << ", population " << King.m_population << endl;	  // Display on the screen the Kingdomname & population information.
	}
}
