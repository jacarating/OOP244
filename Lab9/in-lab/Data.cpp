// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		cout << "Population change from 2000 to 2004 is ";
		int popChange = population[n - 1] - population[0];
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(popChange) / 1000000 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		bool result = violentCrime[0] < violentCrime[n - 1]; // compare values
	    const char* word;
		if (result) {
			word = "up";
		}
		else
			word = "down";

		cout << "Violent Crime trend is " << word << endl;

		// Q3 print the GTA number accurate to 0 decimal places
		double incidents = average(grandTheftAuto, n);
		cout.precision(2);
		cout << "There are " << incidents / 1.0E6 << " million Grand Theft Auto incidents on average a year" << endl;


		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;


	}
}