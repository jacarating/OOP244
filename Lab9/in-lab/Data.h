// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca


#include <iostream>
#include <istream>
#include <cstring>
using namespace std;


namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;


	template <typename T>
	T max(const T* data, int n) {
		T largest = data[0];
		for (int i = 1; i < n; i++) { // start at 1 because smallest is assigned to first element already.
			if (largest < data[i] && largest <= LARGEST_NUMBER)
				largest = data[i];
		}
		return largest;
	}

	template <typename T>
	T min(const T* data, int n) {
		T smallest = data[0];
		for (int i = 1; i < n; i++) { // start at 1 because largest is assigned to first element already.
			if (smallest > data[i] && smallest >= SMALLEST_NUMBER)
				smallest = data[i];
		}
		return smallest;
	}
   
	template <typename T>
	T sum(const T* data, int n) {
		T temp = 0;
		for (int i = 0; i < n; i++) {
			temp += data[i];
		}
		return temp;
	}

	template <typename T>
	double average(const T* data, int n) {
		return sum(data, n) / n;
	}

	template <typename T>
	bool read(std::istream& input, T* data, int n) {
		bool result = true;
		for (int i = 0; i < n; ++i){
			input.ignore();
			input >> data[i];
			if (input.fail())
				result = false;
		}
		return result;
	}

	template <typename T>
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << right << name;
		
		for (int i = 0; i < n; i++) {
			cout.width(COLUMN_WIDTH);
			cout << data[i];
		}
		cout << endl;
	}


	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

