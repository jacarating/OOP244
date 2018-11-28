// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include <cstring>
#include "Good.h"
#include "Error.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
namespace aid {
	void Good::name(const char* tName) {
		int length = strlen(tName);
		if (tName != nullptr) {
			goodName = new char[length+1];
			for (int i = 0; i < length; i++) {
				goodName[i] = tName[i];
			}
			goodName[strlen(tName)] = '\0';
		}
		else { 
			goodName = nullptr;  
		}
	}

	const char* Good::name() const {
		return goodName[0] == '\0' || goodName == nullptr ? nullptr : goodName; 
	}

	const char* Good::sku() const {
		return goodSku;
	}

	const char* Good::unit() const {
		return goodUnit;
	}

	bool Good::taxed() const {
		return theTax;
	}

	double Good::itemPrice() const {
		return unitPrice;
	}

	double Good::itemCost() const {
		return taxed() ? (unitPrice * taxRate) : unitPrice;
	}

	void Good::messages(const char* tMessage) {
		error.message(tMessage);
	}

	bool Good::isClear() const {
		return error.isClear();
	}

	Good::Good(char typeE) {
		type = typeE;
		goodSku[0] = '\0';
		goodUnit[0] = '\0';
		goodName = nullptr;
		goodQuantity = 0;
		goodNeeded = 0;
		unitPrice = 0;
		theTax = false;
	}

	Good::Good(const char* tSku, const char* tName, const char* tUnit, int tQuantity, bool tax, double tPrice, int tNeeded) {
		theTax = tax;
		strncpy(goodSku, tSku, max_sku_length);
		goodSku[max_sku_length] = '\0';
		name(tName);
		strncpy(goodUnit, tUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';
		goodQuantity = tQuantity;
		goodNeeded = tNeeded;
		unitPrice = tPrice;
			
	}

	Good::Good(const Good& source) {
		*this = source;
	}

	Good& Good::operator=(const Good& source) {
		if (this != &source) { // check for self-assignment
			type = source.type;
			strncpy(goodSku, source.goodSku, max_sku_length);
			goodSku[max_sku_length] = '\0';
			strncpy(goodUnit, source.goodUnit, max_unit_length);
			goodUnit[max_unit_length] = '\0';
			name(source.goodName);
			goodQuantity = source.goodQuantity;
			goodNeeded = source.goodNeeded;
			unitPrice = source.unitPrice;
			theTax = source.theTax;
			error.message(source.error.message());
		}
		return *this;
	}

	Good::~Good() {
		delete[] goodName;
		goodName = nullptr;
		error.clear();
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const {
		file << type << ',' << goodSku << ',' << goodUnit << ',' << goodName << ',' << goodQuantity;
		if (newLine == true) {
			file << endl;
		}
		return file;
	}

	std::fstream& Good::load(std::fstream& file) {
		Good temp;
		temp.goodName = new char[max_name_length + 1];
		file >> temp.type >> temp.goodSku >> temp.goodUnit >> temp.goodName >> temp.goodQuantity; // output data members
		*this = temp;
		delete[] temp.goodName;
		temp.goodName = nullptr;
		return file;
	}

	std::ostream& Good::write(std::ostream& os, bool linear) const {
		if (!isEmpty()) { 
			if (!error.isClear())
				os << error.message();
			if (linear) {
				os.fill(); // default for fill is spaces
				os.setf(ios::left); // Set the format aligned to the left..
				os.width(max_sku_length);
				os << goodSku << '|';
				os.width(20);
				os << goodName << '|';
				os.unsetf(ios::left); // Unset the format for reformatting
				os.setf(ios::right);
				os.width(7);
				os.setf(ios::fixed);
				os.precision(2);
				os << itemCost() << '|';
				os.width(4);
				os << goodQuantity << '|';
				os.unsetf(ios::right);
				os.setf(ios::left);
				os.width(10);
				os << goodUnit << '|';
				os.unsetf(ios::left); 
				os.setf(ios::right);
				os.width(4);
				os << goodNeeded << '|';
				os.unsetf(ios::right);
			}
			else {
				os << "Sku: " << goodSku << endl;
				os << "Name (no spaces): " << endl;
				os << "Price: " << unitPrice << endl;

				if (theTax)
					os << "Price after tax: " << itemCost() << endl;
				else
					os << "N/A" << endl;


				os << "Quantity on hand: " << goodQuantity << endl;
				os << "Quantity needed: " << goodNeeded << endl;
			}
		}

		return os;
	}

	std::istream& Good::read(std::istream& is) {
		char taxed_;
		char tName[max_name_length + 1];

		Good temp;

		cout << " Sku: ";
		is >> temp.goodSku;

		cout << " Name (no spaces): ";
		is >> tName;

		cout << " Unit: ";
		is >> temp.goodUnit;

		cout << " Taxed? (y/n): ";
		is >> taxed_;

		if (taxed_ == 'Y' || taxed_ == 'y')
			temp.theTax = true;
		else if (taxed_ == 'N' || taxed_ == 'n')
			temp.theTax = false;
		else {
			is.setstate(ios::failbit);
			temp.error.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail()) {
			cout << " Price: ";
			is >> temp.unitPrice;
			if (is.fail())
				temp.error.message("Invalid Price Entry");
		}

		if (!is.fail()) {
			cout << " Quantity on hand: ";
			is >> temp.goodQuantity;
			if (is.fail())
				temp.error.message("Invalid Quantity Entry");
		}

		if (!is.fail()) {
			cout << " Quantity needed: ";
			is >> temp.goodNeeded;
			if (is.fail())
				temp.error.message("Invalid Quantity Needed Entry");
		}

		if (!is.fail()) {
			temp.name(tName);
			*this = temp;
		}

		return is;
	}

	bool Good::operator==(const char* temp) const {
		return strcmp(temp, goodSku) == 0;
	}

	double Good::total_cost() const {
		return itemCost() * goodQuantity;
	}

	void Good::quantity(int units) {
		if (units > 0)
			goodQuantity = units;
	}

	bool Good::isEmpty() const {
		return goodName == nullptr;
	}

	int Good::qtyNeeded() const {
		return goodNeeded;
	}

	int Good::quantity() const {
		return goodQuantity;
	}

	bool Good::operator>(const char* sku) const {
		return strcmp(sku, goodSku) > 0;
	}

	bool Good::operator>(const Good& temp) const {
		return strcmp(temp.goodName, goodName) > 0;
	}

	int Good::operator+=(int units) {
		return units > 0 ? goodQuantity += units : goodQuantity;
	}

	std::ostream& operator<<(std::ostream& tempOs, const Good& tempObj) {
		return tempObj.write(tempOs, true);
	}

	std::istream& operator>>(std::istream& tempIs, Good& tempObj) {
		tempObj.read(tempIs);
		return tempIs;
	}

	double operator+=(double& tempCost, const Good& tempObj) {
		return tempCost += tempObj.total_cost();
	}
}