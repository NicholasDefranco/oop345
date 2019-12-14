// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguard
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

// include files
#include <iostream>
#include <string>

namespace sdds 
{

	// Represents 12:00 pm
	const int NOON {12};

	const int NAME_WIDTH {10};

	const int EMAIL_WIDTH {20};

	class Reservation 
	{
		// each data member represents a field each record has
		//
		// I have chosen std::string as the std::string class
		// contains plenty of member functions which can assist in
		// my string parsing algorithm.
		std::string id {};
		std::string name {};
		std::string email {};

		unsigned no {0u};
		unsigned day {0u};
		unsigned hour {0u};

		public:

		// default constructor
		Reservation() = default;

		// one-arg constructor
		Reservation(const std::string& res);

		// inserts data stored in the object to the output stream
		// in a human-readable format
		friend std::ostream& operator<<
			(std::ostream& os, const Reservation& r);

	};

} // sdds namespace

#endif // SDDS_RESERVATION_H
