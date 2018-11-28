// Jacob Carating
// 157 725 177
// jacarating@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace aid {


	Error::Error(const char* errorMessage) {
		if (errorMessage == nullptr || errorMessage[0] == '\0') {
			messages = nullptr;
		}
		else {
			messages = new char[strlen(errorMessage) + 1];
			strncpy(messages, errorMessage, strlen(errorMessage) + 1);
		}

	}

	Error::~Error() {
		delete[] messages;
		messages = nullptr;
	}


	void Error::clear() {
		delete[] messages;
		messages = nullptr;
	}

	bool Error::isClear() const {
		return messages == nullptr || messages[0] == '\0' ? true : false;
	}

	void Error::message(const char * str) {
		if (str != nullptr && str[0] != '\0') {
			delete[] messages;
			messages = new char[strlen(str) + 1];
			strncpy(messages, str, strlen(str) + 1);
		}
		else {
			delete[] messages;
			messages = nullptr;
		}
	}

	const char* Error::message() const {
		return !isClear() ? messages : nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Error& source) {
		if (!source.isClear()) {
			os << source.message();
		}
		return os;
	}

}