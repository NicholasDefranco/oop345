// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safe guard
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

// include files
#include <iostream>
#include "Reservation.h"

namespace sdds 
{

	class Restaurant 
	{

		// each element in this array will hold the value of a
		// Reservation object which is managed within the class
		// (composition)
		Reservation *reserves {nullptr};

		// size of the dynamic array
		size_t no {0u};

		public:
		// two-arg constructor
		// recieves a array pointers to Reservation objects (along
		// with the size). copies the value of the Reservation
		// object for each address and stores it into the current
		// object
		Restaurant(Reservation **reservations, size_t no);

		// copy constructor
		Restaurant(const Restaurant& r);

		// copy assingment operator
		Restaurant& operator=(const Restaurant& r);

		// move constructor
		Restaurant(Restaurant&& r);

		// move assignment operator
		Restaurant& operator=(Restaurant&& r);

		// destructor
		~Restaurant();

		// returns the size of the array
		inline size_t size() const;

		// inserts data stored in each Reservation object to 
		// the output stream in a human-readable format
		friend std::ostream& operator<<
			(std::ostream& os, const Restaurant& r);

	};

} // sdds namespace

#endif // SDDS_RESTAURANT_H
