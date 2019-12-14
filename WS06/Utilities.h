// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

// include files
#include "Vehicle.h"

namespace sdds
{
	// Returns the address of a dynamically allocated instance within 
	// the vechicle hierarchy (polymorphic object)
	//                           
	// The dynamic type of the polymorphic obejct returned
	// is specified by the first field in the input stream recieved in
	// the parameter list 
	Vehicle *createInstance(std::istream& in);
}

#endif // SDDS_UTILITIES_H
