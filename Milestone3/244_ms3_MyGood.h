// Final Project - Milestone 3 - MyGood and Test Modules
// Version 3.4.1
// Date	2018-11-15
// 244_ms3_MyGood.h
// Author	Fardad Soleimanloo, Chris Szalwinski
//
// For you final test before submission:
//      DO NOT MODIFY THIS FILE IN ANY WAY
//
// Revision History
// --------------------------------------------------------------
// Name               Date                 Reason
// Chris              2018-02-08           Removed polymorphism
// Chris              2018-03-02           Final Draft 20181
// Chris              2018-03-03           ErrorMessage -> Error
// Chris              2018-10-18           for Fall 2018
// Chris              2018-11-15           price and cost ids changed
/////////////////////////////////////////////////////////////////

#ifndef AID_MY_GOOD_H
#define AID_MY_GOOD_H
#include <fstream>
#include "Good.h"

namespace aid {
	class MyGood : public Good {
	public:
		MyGood();
		MyGood(const char* sku, const char* name, const char* unit, int qty = 0,
			bool isTaxed = true, double price = 0.0, int qtyNeeded = 0);
		const char* sku() const;
		const char* name() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
	};

	class Test {
		MyGood product;
		const char* filename;
	public:
		Test(const char* file);
		Test(const char* file, const char* theSku, const char* theName);
		std::fstream& store(std::fstream& file, bool addNewLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		int operator+=(int value);
		bool operator==(const char* sku) const;
		friend std::ostream& operator<<(std::ostream& os, const Test& test);
		friend double operator+=(double& d, const Test& test);
		friend std::istream& operator>>(std::istream& is, Test& test);
	};
}
#endif
