// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

// include files
#include <iostream>
#include <string>

namespace sdds 
{
	class Movie {

		// each data member represents a field each record has
		std::string title {};
		size_t year {0u};
		std::string desc {};

		public:

		// default constructor
		Movie() = default;

		// one-arg constructor
		// extracts information from the string and stores the 
		// information in the instance variables
		explicit Movie(const std::string& str);

		// Accessor
		const std::string& gettitle() const noexcept;

		// recieves a functor that fixes spelling of strings
		template<typename T>
		void revise(T check) 
		{
			check(desc);
			check(title);
		}

		// inserts data stored in the object to the output stream
		// in a human-readable format
		friend std::ostream& operator<<
			(std::ostream& os, const Movie& m);
	};

	// redeclaration of the trim function
	// previously declared in the Book module
	void trim(std::string& str);

} // namespace sdds

#endif // SDDS_MOVIE_H
