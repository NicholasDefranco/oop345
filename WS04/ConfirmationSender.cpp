// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 8th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// include file
#include "ConfirmationSender.h"

namespace sdds 
{

	// copy constructor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& c) {
		*this = c;
	}

	// copy assignment operator
	ConfirmationSender& ConfirmationSender::operator=
					(const ConfirmationSender& c) 
	{
		if(this != &c) {
			this->no = c.no;
			delete [] this->reserves;
			if(c.reserves != nullptr) {
				this->reserves = 
					new const Reservation *[this->no];
				for(size_t i = 0; i < no; i++) {
					this->reserves[i] = c.reserves[i];
				}
			} else {
				this->reserves = nullptr;
			}
		}
		return *this;
	}

	// move constructor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& c) 
	{
		*this = std::move(c);
	}

	// move assignment
	ConfirmationSender& ConfirmationSender::operator=
					(ConfirmationSender&& c) 
	{
		if(this != &c) {
			delete [] this->reserves;	

			this->reserves = c.reserves;
			this->no = c.no;

			c.reserves = nullptr;
			c.no = 0u;
		}
		return *this;
	}

	// destructor
	ConfirmationSender::~ConfirmationSender() 
	{
		delete [] this->reserves;
	}

	// adds the address of the Reservation object
	// into the array if it does not already exist 
	ConfirmationSender& ConfirmationSender::operator+=
						(const Reservation& res) 
	{
		if(lsearch(reserves, &res, no) == no) {
			const Reservation **tmp = reserves;
			this->reserves = new const Reservation *[no + 1];
			if(tmp != nullptr) {
				for(size_t i = 0; i < no; i++) {
					this->reserves[i] = tmp[i];
				}
			}
			this->reserves[no++] = &res;
			delete [] tmp;
		}
		return *this;
	}

	// removes the address of the Reservation object
	// from the array if it exists
	ConfirmationSender& ConfirmationSender::operator-=
					(const Reservation& res) 
	{
		size_t index = lsearch(reserves, &res, no);

		if(index != no) {
			this->reserves[index] = nullptr;
			const Reservation **tmp = reserves;
			this->reserves = new const Reservation *[no - 1];
			size_t diff = 0;
			for(size_t i = 0; i < no; i++) {
				if(tmp[i] != nullptr) {
					this->reserves[i - diff] = tmp[i];
				} else {
					diff = 1;
				}
			}
			this->no--;
			delete [] tmp;
		}
		return *this;
	}

	// inserts data stored in each Reservation object to 
	// the output stream in a human-readable format
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c)
	{
		os << "--------------------------" << std::endl
		<< "Confirmations to Send" << std::endl
		<< "--------------------------" << std::endl;

		if(c.no > 0) {
			for(size_t i = 0; i < c.no; i++) {	
				os << *c.reserves[i];
			}
		} else {
			os << "The object is empty!" << std::endl;
		}
		return os << "--------------------------" << std::endl;
	}

} // sdds namespace
