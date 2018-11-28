// Final Project - Milestone 5
// Version 3.4
// Allocator_prof.cpp
// 2018-10-18
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Chris              2018-10-18           fall 2018
/////////////////////////////////////////////////////////////////
#include "Good.h"
#include "Perishable.h"

namespace aid {

	// creates an empty good
	//
	iGood* CreateGood() {
		return new Good();
	}

	// creates an empty perishable good
	//
	iGood* CreatePerishable() {
		return new Perishable();
	}
}