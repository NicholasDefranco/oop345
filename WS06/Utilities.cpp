// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <limits>
#include "Racecar.h"
#include "Utilities.h"

namespace sdds
{
	// Returns the address of a dynamically allocated instance within 
	// the vechicle hierarchy (polymorphic object)
	//                           
	// The dynamic type of the polymorphic obejct returned
	// is specified by the first field in the input stream recieved in
	// the parameter list 
	Vehicle *createInstance(std::istream& is)
	{
		char type {EOF};
		Vehicle *tmp {nullptr};

		is >> type;
		if(is.good()) {
			is.ignore(std::numeric_limits
					<std::streamsize>::max(), ',');

			if(type == 'c' || type == 'C')
				tmp = new Car(is);
			else if(type == 'r' || type == 'R')
				tmp = new Racecar(is);
			else
				throw std::string("Unrecognized ")
						+ "record type: "
						+ "[" + type + "]";

		}

		return tmp;
	}
}
