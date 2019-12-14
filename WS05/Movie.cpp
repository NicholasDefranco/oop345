// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include "Movie.h"

namespace sdds 
{
	// one-arg constructor
	// extracts information from the string and stores the 
	// information in the instance variables
	Movie::Movie(const std::string& str) 
	{
		std::stringstream ss(str);

		getline(ss, title, ',');
		trim(title);

		ss >> year;
		ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');

		getline(ss, desc);
		trim(desc);

	}

	// Accessor
	const std::string& Movie::gettitle() const noexcept
	{
		return title;
	}

	// inserts data stored in the object to the output stream
	// in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Movie& m) 
	{
		return os << std::setw(40) << m.title << " | " << std::setw(4) 
			<< m.year << " | " << m.desc << std::endl;
	}

}
