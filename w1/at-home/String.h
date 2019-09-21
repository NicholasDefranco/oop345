// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Wednesday, Spetember 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Header safeguard
#ifndef SDDS_STRING_H
#define SDDS_STRING_H

#include <iostream>

namespace sdds 
{

	// refer to unsigned integer variable defined in String.cpp
	extern unsigned g_maxSize;

	class String {

		// statically allocated character array.
		char *str { nullptr };

		public:
		// one-argument constructor.
		String(const char *);

		// Rule of 3
		// destructor
		~String();
		// Copy constructor
		String(const String&);
		// Copy assignment operator
		String& operator=(const String&);

		// inserts the str data member into the output stream.
		std::ostream& display(std::ostream&) const;

	};

	// Inserts String object into the stream with a counter in the format.
	// COUNTER: str
	std::ostream& operator<<(std::ostream&, const String&);

}

#endif // SDDS_STRING_H
