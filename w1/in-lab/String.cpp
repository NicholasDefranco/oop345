// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, Spetember 13th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Include files
#include <iostream>
#include <cstring>
#include "String.h"

namespace sdds 
{

	unsigned g_maxSize {3u};

	// One-argument constructor.
	String::String(const char *str) 
	{
		if(!(str == nullptr || str[0] == '\0')) 
			std::strncpy(this->str, str, MAX);	
		else 
			this->str[0] = '\0';
	}

	// Copy constructor
	String::String(const String& s) 
	{
		*this = s;
	}

	// Copy assignment operator
	String& String::operator=(const String& s)
	{

		if(this != &s) 
			std::strncpy(this->str, s.str, MAX);	

		return *this;
	}

	// Inserts the str data member into the output stream.
	inline std::ostream& String::display(std::ostream& os) const 
	{
		return os << this->str;	
	}

	// Inserts String object into the stream with a counter in the format.
	// COUNTER: str
	std::ostream& operator<<(std::ostream& os, const String& s) 
	{
		static unsigned count {0};
		os << ++count << ": ";
		return s.display(os);
	}

}
