// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// include files
#include <iostream>
#include "Restaurant.h"

namespace sdds 
{

	// two-arg constructor
	// recieves a array pointers to Reservation objects (along
	// with the size). copies the value of the Reservation
	// object for each address and stores it into the current
	// object
	Restaurant::Restaurant(Reservation **reservations, size_t no) 
	{
		if(reservations != nullptr && no > 0) {
			this->reserves = new Reservation[no];
			for(size_t i {0u}; i < no; i++) {
				this->reserves[i] = *(reservations[i]);
			}
			this->no = no;
		}
	}

	// copy constructor
	Restaurant::Restaurant(const Restaurant& r) 
	{
		*this = r;
	}

	// copy assignment operator
	Restaurant& Restaurant::operator=(const Restaurant& r) 
	{
		if(this != &r) {
			this->no = r.no;
			delete [] this->reserves;
			if(r.reserves != nullptr) {
				this->reserves = new Reservation[this->no];
				for(size_t i = 0u; i < this->no; i++) {
					this->reserves[i] = r.reserves[i];
				}
			} else {
				this->reserves = nullptr;
			}
		}
		return *this;
	}

	// move constructor
	Restaurant::Restaurant(Restaurant&& r) 
	{
		*this = std::move(r);
	}

	// move assignment operator
	Restaurant& Restaurant::operator=(Restaurant&& r) 
	{
		if(this != &r) {
			delete [] this->reserves;

			this->reserves = r.reserves;
			this->no = r.no;

			r.no = 0u;
			r.reserves = nullptr;

		}
		return *this;
	}

	// destructor
	Restaurant::~Restaurant() 
	{
		delete [] reserves;
	}

	// returns the size of the array
	size_t Restaurant::size() const 
	{
		return no;
	}

	// inserts data stored in each Reservation object to 
	// the output stream in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Restaurant& r) 
	{
		os << "--------------------------" << std::endl
		<< "Fancy Restaurant" << std::endl
		<< "--------------------------" << std::endl;
		if(r.no > 0) {
			for(size_t i = 0; i < r.no; i++) {
				os << r.reserves[i];
			}
		} else {
			os << "The object is empty!" << std::endl;	
		}
		return os << "--------------------------" << std::endl;
	}

} // sdds namespace
