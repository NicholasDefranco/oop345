// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

// include files
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle *> vehicles;

		public:
		// Adds the Vehicle pointer recieved in the parameter list
		// into the vector
		Autoshop& operator+=(Vehicle *v);

		// display all the vehicles stored in the vehicles vector
		// in human-readable format
		void display(std::ostream& os) const;

		// for every vechicle that is stored in the current object that
		// passes test, that vechicle is added to the list in the 
		// second parameter
		template<typename T>
		inline void select(T test, std::list<const Vehicle *>& v) const
		{
			// original solution
			//std::vector<Vehicle *>::const_iterator i;
			//for(i = vehicles.cbegin(); i != vehicles.cend(); i++)
				//if(test(*i))
					//v.push_back(*i);

			std::copy_if(vehicles.cbegin(), vehicles.cend(), 
					back_inserter(v), test);
		}

		// destructor
		~Autoshop();

	};
}

#endif
