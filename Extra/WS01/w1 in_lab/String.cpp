#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

namespace sict {
	
	String::String(const char *str) {
		if(str == nullptr || str[0] == '\0') {
			this->str[0] = '\0';
		} else {
			strncpy(this->str, str, MAX);
		}
	}

	ostream& String::display(ostream& os) const {
		return os << this->str;
	}

	ostream& operator<<(ostream& os, const String& s) {
		return s.display(os);
	}

}
