// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include "Car.h"

namespace sdds 
{
	// custom one-arg constructor               
	// reads from the recieved input stream in,
	// and stores information read into the data members
	Car::Car(std::istream& is) 
	{
		getline(is, make, ',');
		trim(make);

		is >> con;
		if(con == ',')
			con = 'n';
		else if(con != 'n' && con != 'u' && con != 'b')
			is.setstate(std::ios::failbit);
		else
			is.ignore(std::numeric_limits
					<std::streamsize>::max() , ',');

		is >> maxspeed;
		if(is.fail()) {
			is.clear();
			throw std::string("Invalid record!");
		}

	}

	// returns a string representing the condition of the car
	std::string Car::condition() const
	{
		std::string tmp;

		if(con == 'n')
			tmp = "new";
		else if(con == 'u')
			tmp = "used";
		else if(con == 'b')
			tmp = "broken";

		return tmp;
	}

	double Car::topSpeed() const noexcept
	{
		return maxspeed;
	}

	// displays the data stored in the object in a human-readable
	// format
	void Car::display(std::ostream& os) const
	{
		os << "| " << std::setw(MAKE_WIDTH) << make << " | " 
				<< std::setw(CON_WIDTH) << std::left 
				<< condition() << std::right << " | " 
				<< std::setw(MAXSPEED_WIDTH) << std::fixed
				<< std::setprecision(MAXSPEED_PREC) 
				<< topSpeed() << " |" 
				<< std::setprecision(DEFAULT_PREC);

		os.unsetf(std::ios::fixed);
	}

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str)
	{
		size_t i = str.find_first_not_of(' ');
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}
}
