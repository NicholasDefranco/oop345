// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesay, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

// include files
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double booster {0.0};	

		public:
		// custom one-arg constructor               
		// reads from the recieved input stream in,
		// and stores information read into the data member
		Racecar(std::istream& is);

		// displays the data stored in the object in a human-readable
		// format
		void display(std::ostream& os) const override;

		double topSpeed() const noexcept override;

		~Racecar() override = default;
	};
}

#endif // SDDS_RACECAR_H
