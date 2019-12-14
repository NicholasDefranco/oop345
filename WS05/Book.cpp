// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// include files
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <typeinfo>
#include <limits>
#include "Book.h"

namespace sdds 
{
	// one-arg constructor
	// extracts information from the string and stores the 
	// information in the instance variables
	Book::Book(const std::string& book) 
	{

		std::stringstream ss(book);

		getline(ss, author, ',');
		trim(author);

		getline(ss, title, ',');
		trim(title);

		getline(ss, country, ',');
		trim(country);

		ss >> price;
		ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');

		ss >> year;
		ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');

		getline(ss, desc);
		trim(desc);
	}

	// Accessors
	const std::string& Book::gettitle() const noexcept
	{
		return title;
	}

	const std::string& Book::getcountry() const noexcept
	{
		return country;	
	}

	const size_t& Book::getyear() const noexcept
	{
		return year;
	}

	// (Accessor) returns a modifiable reference to the price data member
	// allowing the client to change the value of the price data member
	double& Book::getprice() noexcept
	{
		return price;
	}

	// inserts data stored in the object to the output stream
	// in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Book& b) 
	{
		os << std::setw(20) << b.author << " | " 
			<< std::setw(22) << b.title << " | " << std::setw(5) 
			<< b.country << " | " << std::setw(4) << b.year  
			<< " | " << std::setw(6) << std::fixed 
			<< std::setprecision(2) << b.price 
			<< " | " << std::setprecision(DEFAULT_PRECISION) 
			<< b.desc << std::endl;
			
			// there is no iomanip operator to unset fixed
			// it must be unset with member function unsetf
			os.unsetf(std::ios::fixed);
			return os;

	}

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str) 
	{
		size_t i {str.find_first_not_of(' ')};
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}

} // sdds namespace
