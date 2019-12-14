// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 19th, 2019
//
// This file was provided to me by my professor
// 	no changes were made on my part

// header safeguards
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


// include files
#include "List.h"
#include "Element.h"

namespace sdds {
	// both functions recieve a list of Description objects and Price 
	// objects this function creates a list of Products from the matching
	// codes from the two recieved lists
	List<Product> mergeRaw(const List<Description>& desc, 
						const List<Price>& price);

	List<Product> mergeSmart(const List<Description>& desc, 
						const List<Price>& price);
}

#endif // SDDS_UTILITIES_H
