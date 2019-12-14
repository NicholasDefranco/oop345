// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, Spetember 24th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include "TimedEvents.h"

namespace sdds 
{

	// starts timer
	void TimedEvents::startClock() 
	{
		start = std::chrono::steady_clock::now();
	}

	// ends timer
	void TimedEvents::stopClock() 
	{
		end = std::chrono::steady_clock::now(); 
	}

	// updates next available element in the record array
	// with time it took doing an operation
	void TimedEvents::recordEvent(const char *event) 
	{
		if(no < MAX) {
			records[no].event = event;
			records[no].units = "nanoseconds";
			records[no].duration = std::chrono::duration_cast
				<std::chrono::nanoseconds>(end - start);
			no++;
		}
	}

	// inserts data stored in array to the output stream
	// in a human-readable form
	std::ostream& operator<<(std::ostream& os, const TimedEvents& t)
	{
		os << "--------------------------" << std::endl
		<< "Execution Times:" << std::endl
		<< "--------------------------" << std::endl;
		for(unsigned i = 0; i < t.no; i++) {
			os << std::setw(20) << std::left << t.records[i].event 
			<< ' ' << std::right << std::setw(12) 
			<< t.records[i].duration.count() 
			<< ' ' << t.records[i].units << std::endl;
		}
		os.unsetf(std::ios::right);

		os << "--------------------------" << std::endl;
		return os;
	}

}
