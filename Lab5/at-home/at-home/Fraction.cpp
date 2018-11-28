// Author: Jacob Carating
// ID: 157 725 177
// Email: jacarating@myseneca.ca

// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numer = 0;
		denom = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int a, int b) {
		if (a > 0 && b > 0) {
			numer = a;
			denom = b;
			reduce();
		}
		else
			*this = Fraction();
	}
	// TODO: implement the max query
	int Fraction::max() const {
		if (numer > denom) {
			return numer;
		}
		else
			return denom;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		if (numer < denom) {
			return numer;
		}
		else
			return denom;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {	// check to ensure both expressions evaluate to 0
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int grecd = gcd();
		numer = numer / grecd;
		denom = denom / grecd;
	}
	// TODO: implement the display query
	void Fraction::display() const {
		if (isEmpty() == false && denom != 1) {
			cout << numer << "/" << denom;
		}
		else if (isEmpty() == false && denom == 1) {
			cout << numer;
		}else 
			cout << "no fraction stored";
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool result;
		if (numer == 0 && denom == 0) {
			result = true;
		}
		else
			result = false;
		return result;
	}
	// TODO: implement the + operator
	 Fraction Fraction::operator+(const Fraction& rhs) const {
		Fraction tempo;
		if (isEmpty() == false && rhs.isEmpty() == false) {
			tempo.numer = (numer*rhs.denom) + (denom*rhs.numer);
			tempo.denom = denom*rhs.denom;
			tempo.reduce();
		}
		return tempo;
	}

	Fraction Fraction::operator*(const Fraction& rhs) const{
		Fraction temp; // Create temp object
		if (isEmpty() || rhs.isEmpty()) {
			return temp;
		}
		else {
			temp.numer = numer * rhs.numer; // Evaluate and assign values..
			temp.denom = denom * rhs.denom;
			temp.reduce(); // Reduce the fraction
		}
		return temp;
	}

	bool Fraction::operator==(const Fraction& rhs) {
		bool eqNum = numer == rhs.numer;
		bool eqDen = denom == rhs.denom;
		bool result;
		if ((!isEmpty() || !rhs.isEmpty()) && (eqNum && eqDen)) { // Check if equal in value
			result = true;
		}else
			result = false;
		return result;
	}

	bool Fraction::operator!=(const Fraction& rhs) {
		bool uneqNum = numer != rhs.numer;
		bool uneqDen = denom != rhs.denom;
		bool result;
		if (!isEmpty() && !rhs.isEmpty() && uneqNum && uneqDen) {
			result = true;
		}
		else
			result = false;
		return result;
	}

	Fraction Fraction::operator+=(const Fraction& rhs) {
		
		if (isEmpty() || rhs.isEmpty()) {
			*this = Fraction();
		}
		else {
			reduce();
			numer = numer * rhs.denom + denom * rhs.numer;
			denom = denom * rhs.denom;
			
		}


		return *this;
	}
}