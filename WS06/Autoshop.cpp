// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <algorithm>
#include "Autoshop.h"

namespace sdds 
{
	// Adds the Vehicle pointer recieved in the parameter list
	// into the vector
	Autoshop& Autoshop::operator+=(Vehicle *v)
	{
		vehicles.push_back(v);	
		return *this;
	}

	// display all the vehicles stored in the vehicles vector
	// in human-readable format
	void Autoshop::display(std::ostream& os) const
	{
		os << "--------------------------------" << std::endl
			<< "| Cars in the autoshop!        |" << std::endl
			<< "--------------------------------" << std::endl;

		std::for_each(vehicles.cbegin(), vehicles.cend(),
						[&os](Vehicle *v) {
			v->display(os);
			os << std::endl;
		});

		// original solution
		//std::vector<Vehicle *>::const_iterator i;
		//for(i = vehicles.cbegin(); i != vehicles.cend(); i++) {
			//(*i)->display(os);		
			//os << std::endl;
		//}
		os << "--------------------------------" << std::endl;
	}

	// destructor
	Autoshop::~Autoshop()
	{
		std::for_each(vehicles.begin(), vehicles.end(),
						[](Vehicle *v) {
			delete v;
			v = nullptr;
		});

		// original solution
		//std::vector<Vehicle *>::iterator i;
		//for(i = vehicles.begin(); i != vehicles.end(); i++) {
			//delete *i;
			//*i = nullptr;
		//}

		vehicles.clear();
		
	}

}
