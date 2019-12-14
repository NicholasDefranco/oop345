// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safe guard
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

// include files
#include "Reservation.h"

namespace sdds
{
	// aggregation
	class ConfirmationSender {

		// size of the dynamic array
		size_t no {0u};

		// each element in this dynamically allocated array will hold
		// an address of an object that is managed outside the class
		// (aggregation)
		const Reservation **reserves {nullptr};
		
		public:
		// default constructor
		ConfirmationSender() = default;

		// copy constructor
		ConfirmationSender(const ConfirmationSender& c);

		// copy assignment operator
		ConfirmationSender& operator=(const ConfirmationSender& c);

		// move constructor
		ConfirmationSender(ConfirmationSender&& c);

		// move assignment
		ConfirmationSender& operator=(ConfirmationSender&& c);

		// destructor
		~ConfirmationSender();

		// adds the address of the Reservation object
		// into the array if it does not already exist 
		ConfirmationSender& operator+=(const Reservation& res);

		// removes the address of the Reservation object
		// from the array if it exists
		ConfirmationSender& operator-=(const Reservation& res);

		// inserts data stored in each Reservation object to 
		// the output stream in a human-readable format
		friend std::ostream& operator<<
			(std::ostream& os, const ConfirmationSender& r);
	};

	// helper templated linear search function
	// recieves an array, what your looking for, and the size of the array
	// returns the index of the matching element if found
	// returns the size of the array if not found
	template<typename T>
	size_t lsearch(const T **arr, const T *match, size_t size)
	{
		size_t i {0u};
		bool found {false};
		for(i = 0u; i < size && !found; i++) {
			if(match == arr[i]) {
				i--;
				found = true;
			}
		}
		return i;
	
	}

} // sdds namespace

#endif // SDDS_CONFIRMATIONSENDER_H
