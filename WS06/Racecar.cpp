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

namespace sdds
{
	// custom one-arg constructor               
	// reads from the recieved input stream in,
	// and stores information read into the data member
	Racecar::Racecar(std::istream& is) : Car(is)
	{
		is.ignore(std::numeric_limits<std::streamsize>::max(), ',');
		is >> booster;	
	}

	// displays the data stored in the object in a human-readable
	// format
	void Racecar::display(std::ostream& os) const
	{
		Car::display(os);	
		os << '*';
	}

	double Racecar::topSpeed() const noexcept
	{
		return Car::topSpeed() * (1 + booster);
	}
}
