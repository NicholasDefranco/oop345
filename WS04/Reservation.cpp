// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// include files
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include "Reservation.h"

namespace sdds 
{

	// one-arg constructor
	Reservation::Reservation(const std::string& res) 
	{
		// temporary string object, which we can modify
		std::string tmp(res);

		// Required if we cannot assume there will 
		// be a space between the first and second field. Since 
		// the test case does not test for this we do not 
		// actually need this line. (Colon is added back later)
//		tmp[tmp.find(':')] = ' ';

		// replace all ',' with ' '
		std::replace_if(tmp.begin(), tmp.end(), [](char c) {
			return c == ',';	
		}, ' ');

		// create a stream with the string object
		std::stringstream ss(tmp);

		// then just simply collect the data in the order it appears :)

		ss >> id >> name >> email >> no >> day >> hour;
		
		// if using line 30, this line is required
//		id += ':';

		// emails require <> brackets surronding them
		email = '<' + email + '>';


	}

	// inserts data stored in the object to the output stream
	// in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Reservation& r)
	{
		os << "Reservation " << r.id << " "
		<< std::right << std::setw(NAME_WIDTH) << r.name << "  "
		<< std::left << std::setw(EMAIL_WIDTH) << r.email << "   "
		<< std::right;

		if(r.hour >= 6 && r.hour <= 9)
			os << " Breakfast";
		else if(r.hour >= 11 && r.hour <= NOON + 3)
			os << " Lunch";
		else if(r.hour >= NOON + 5 && r.hour <= NOON + 9)
			os << " Dinner";
		else
			os << " Drinks";

		return os << " on day " << r.day << " @ " << r.hour
		<< ":00 for " << r.no << " people." << std::endl;
	}

} // sdds namespace
