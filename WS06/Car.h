// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

// include files
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds 
{
	// constants for display function to avoid magic numbers
	const int MAKE_WIDTH {10};
	const int CON_WIDTH {6};
	const int MAXSPEED_WIDTH {6};
	const int MAXSPEED_PREC {2};

	const int DEFAULT_PREC {6};

	class Car : public Vehicle 
	{
		std::string make {};
		char con {'\0'};
		double maxspeed {0.0};

		public:
		// custom one-arg constructor               
		// reads from the recieved input stream in,
		// and stores information read into the data members
		Car(std::istream& is);

		// accessors
		// returns a string representing the condition of the car
		std::string condition() const override;

		double topSpeed() const noexcept override;

		// displays the data stored in the object in a human-readable
		// format
		void display(std::ostream& os) const override;

		// destructor
		~Car() override = default;
	};

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str);
}

#endif // SDDS_CAR_H
