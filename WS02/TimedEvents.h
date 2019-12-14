// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, Spetember 24th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguard
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

// include files
#include <iostream>
#include <chrono>

namespace sdds 
{

	// Represents the size of the statically allocated array of records
	const size_t MAX {7u};

	class TimedEvents {
		
		// amount of elements currently stored in array
		size_t no {0u};	

		// start time
		std::chrono::steady_clock::time_point start;

		// end time
		std::chrono::steady_clock::time_point end;

		// Anonymous structure with array definition, 
		// array contains execution times of various operations.
		struct {
		
			std::string event;
			std::string units;
			std::chrono::steady_clock::duration duration;
	
		} records[MAX];

		public:

		// default constructor
		TimedEvents() = default;

		// starts timer
		void startClock();	

		// ends timer
		void stopClock();

		// updates next available element in the record array
		// with time it took doing an operation
		void recordEvent(const char *);
	
		// inserts data stored in array to the output stream
		// in a human-readable form
		friend std::ostream& operator<<
			(std::ostream&, const TimedEvents&);

	};

}

#endif // SDDS_TIMEDEVENTS_H
