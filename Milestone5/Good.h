// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#ifndef AID_GOOD_H
#define AID_GOOD_H

#include <iostream>
#include "Error.h"
#include "iGood.h"
namespace aid {

	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxRate = 1.13;
	class Good : public iGood {
		char type;
		char goodSku[max_sku_length];
		char goodUnit[max_unit_length];
		char * goodName;
		int goodQuantity;
		int goodNeeded;
		double unitPrice;
		bool theTax;
		Error error;
	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void messages(const char*);
		bool isClear() const;

	public:
		Good(char typeE = 'N');
		Good(const char*, const char*, const char*, int tQuantity = 0, bool tax = true, double tPrice = 0, int tNeeded = 0);
		Good(const Good&);
		Good& operator=(const Good&);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iGood&) const;
		int operator+=(int);
		
	};

	std::ostream& operator<<(std::ostream&, const iGood&);
	std::istream& operator>>(std::istream&, iGood&);
	double operator+=(double&, const iGood&);





}
#endif // !AID_GOOD_H
