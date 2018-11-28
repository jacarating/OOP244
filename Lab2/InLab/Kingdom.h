/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


namespace sict {		// Structure delcaration
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(Kingdom& King);	// Function prototype.

}
#endif // !
