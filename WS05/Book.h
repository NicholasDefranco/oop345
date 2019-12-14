// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safe guards
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

// include files
#include <iostream>
#include <string>

namespace sdds 
{
	// default precision of ostream
	const size_t DEFAULT_PRECISION {6};

	class Book {

		// each data member represents a field each record has
		std::string author {};
		std::string title {};
		std::string country {};
		size_t year {0u};
		double price {0.0};
		std::string desc {};

		public:
		// default constructor
		Book() = default;

		// one-arg constructor
		// extracts information from the string and stores the 
		// information in the instance variables
		explicit Book(const std::string& book);

		// accessors
		const std::string& gettitle() const noexcept;
		const std::string& getcountry() const noexcept;
		const size_t& getyear() const noexcept;
		// returns a modifiable reference to the price data member
		double& getprice() noexcept;

		// recieves a functor that fixes spelling of strings
		template<typename T>
		void revise(T check) {
			check(desc);
		}

		// inserts data stored in the object to the output stream
		// in a human-readable format
		friend std::ostream& operator<<
			(std::ostream& os, const Book& b);
	};

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str);

} // sdds namespace 

#endif // SDDS_BOOK_H
