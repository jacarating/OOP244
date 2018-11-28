// Final Project Milestone 3 - iGood Interface
// Version 3.4
// 244_ms4_Allocator_prof.cpp
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
#include "244_ms4_MyGood_prof.h"

namespace aid {

	iGood* CreateGood() {
		return new MyGood("Good");
	}
	iGood* CreatePerishable() {
		return new MyGood("Perishable");
	}
}