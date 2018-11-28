// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	const int MAX_CHAR = 20;

	class Contact {
		char name[MAX_CHAR + 1];
		long long* numbers;
		int size;
		bool validNum(const long long pNumbers, int* ccode, int* acode, int* a, int* b) const;
	public:
		Contact();
		Contact(const char* pName, const long long* pNumbers, int psize);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif