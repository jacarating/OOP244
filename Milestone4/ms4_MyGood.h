// Final Project Milestone 4 - iGood Interface
// Version 3.4
// ms4_MyGood.h
// 2018/11/21
// Authors	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2017-07-11           corrected compile safegaurds
// Chris              2017-12-02           Streamable -> Product
// Chris              2017-12-06           C++17 -> C++11
// Chris              2018-01-25           Product -> iGood
// Chris              2018-03-03           ErrorMessage -> ErrorState
// Chris              2018-03-10           Matching specs
// Chris              2018-10-18           fall 2018
/////////////////////////////////////////////////////////////////
#ifndef AID_MY_GOOD_H
#define AID_MY_GOOD_H
#include "iGood.h"
#include "iGood.h"
#include "iGood.h" // Good.h is included three times on purpose.

namespace aid {
  class MyGood : public iGood {
    char text_[10000];
	char sku[4];
	char name_[20];
	int value;
  public:
    MyGood(const char* name);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
	bool operator==(const char*) const;
	double total_cost() const;
	const char* name() const;
	void quantity(int);
	int qtyNeeded() const;
	int quantity() const;
	int operator+=(int);
	bool operator>(const iGood&) const;
  };
}
#endif