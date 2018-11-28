// Student: Jacob Carating
// ID: 157 157 725
// Email: jacarating@myseneca.ca
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define LIMIT 19

namespace sict {
	class Passenger {

		char passName[LIMIT];
		char passDest[LIMIT];
	public:
		Passenger();
		Passenger(const char *passName, const char *destination);
		bool isEmpty() const;
		void display() const;
	};

}
#endif // !SICT_PASSENGER_H