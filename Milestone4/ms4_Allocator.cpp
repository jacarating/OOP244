// Final Project Milestone 3 - iGood Interface
// Version 3.4
// ms4_Allocator.cpp
// 2018/11/21
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
#include "ms4_MyGood.h"

namespace aid {

	iGood* CreateGood() {
		return new MyGood("Good");
	}
	iGood* CreatePerishable() {
		return new MyGood("Perishable");
	}
}