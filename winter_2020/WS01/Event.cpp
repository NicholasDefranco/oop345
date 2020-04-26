#include <iostream>
#include <iomanip>
#include <cstring>
#include "Event.h"

size_t g_sysClock {0ul};

namespace sdds {

	Event::Event(const Event& e)
	{
		*this = e;
	}

	Event& Event::operator=(const Event& e)
	{
		if(this != &e) {
			start = e.start;

			delete [] desc;
			if(e.desc != nullptr) {
				desc = new char[strlen(e.desc) + 1];
				strcpy(desc, e.desc);
			} else {
				desc = nullptr;
			}
		}
		return *this;
	}

	Event::~Event() 
	{
		delete [] desc;
	}

	void Event::display() 
	{
		static unsigned count {1u};
		std::cout << std::setw(NUM_WIDTH) << count++ << ". ";
		if(desc != nullptr && desc[0] != '\0') {
			std::cout << std::setfill('0') << std::setw(NUM_WIDTH) 
				<< start / 60 / 60 << ':' 
				<< std::setw(NUM_WIDTH) << start / 60 % 60 
				<< ':' << std::setw(NUM_WIDTH) << start % 60 
				<< " -> " << desc << std::setfill(' ');
		} else {
			std::cout << "[ No Event ]";
		}
		std::cout << std::endl;
	}

	void Event::setDescription(char *d)
	{
		if(d == nullptr || d[0] == '\0') {
			*this = Event();
		} else {
			delete [] desc;
			desc = new char[strlen(d) + 1];
			strcpy(desc, d);
			start = g_sysClock;
		}
	}

}
