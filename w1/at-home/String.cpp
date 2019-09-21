// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Wednesday, Spetember 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Include files
#include <iostream>
#include <cstring>
#include "String.h"

namespace sdds 
{

	// represents max size of string
	unsigned g_maxSize {3u};

	// One-argument constructor.
	String::String(const char *str) 
	{
		if(!(str == nullptr || str[0] == '\0')) {
			size_t len = std::strlen(str);
			len = len > g_maxSize ? g_maxSize : len;	
			this->str = new char[len + 1];
			std::strncpy(this->str, str, len);
		} else {
			this->str = nullptr;
		}
	}

	// destructor
	String::~String() 
	{
		delete [] str;
	}

	// Copy constructor
	String::String(const String& s) 
	{
		this->str = nullptr;
		*this = s;
	}

	// Copy assignment operator
	String& String::operator=(const String& s)
	{
		if(this != &s) {
			delete [] this->str;
			if(s.str != nullptr) {
				size_t len = std::strlen(s.str);
				this->str = new char[len + 1];
				std::strncpy(this->str, s.str, len);
			} else {
				this->str = nullptr;
			}
		}
		return *this;
	}

	// Inserts the str data member into the output stream passed as 
	// parameter
	inline std::ostream& String::display(std::ostream& os) const 
	{
		return os << this->str;	
	}

	// Inserts String object into the stream with a counter in the format.
	// COUNTER: str
	std::ostream& operator<<(std::ostream& os, const String& s) 
	{
		static unsigned count {0u};
		os << ++count << ": ";
		return s.display(os);
	}

}
