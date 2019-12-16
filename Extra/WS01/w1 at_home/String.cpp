#include <iostream>
#include <cstring>
#include "String.h"
#include "w1.h"

using namespace std;

extern const int INITIAL;

namespace sict {
	
	String::String(const char *str) {
		if(str == nullptr || str[0] == '\0') {
			this->str = nullptr;
		} else {
			unsigned len = strlen(str);
			this->str = new char[len + 1];
			strncpy(this->str, str, len);
			this->str[len] = '\0';
		}
	}

	String::~String() {
		delete [] this->str;
	}

	ostream& String::display(ostream& os) const {
		return os << this->str;
	}

	ostream& operator<<(ostream& os, const String& s) {
		static unsigned count = INITIAL;
		os << count++ << ": ";
		return s.display(os);
	}

}
