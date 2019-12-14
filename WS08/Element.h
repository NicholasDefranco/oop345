// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 19th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// header safeguards
#ifndef SDDS_ELEMENT_H
#define SDDS_ELEMENT_H

// include files
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace sdds {

	struct Description {
		unsigned code {0u};
		std::string desc {};

		// reads a line of data from the reference to an 
		// input file stream object
		bool load(std::ifstream& f) 
		{
			f >> code >> desc;
			return f.good();
		}

		// inserts the data stored in the current Description object 
		// into the reference to the ostream object in human-readable 
		// form
		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code
				<< std::setw(FWD) << desc
				<< std::endl;
		}
	};

	struct Price {
		unsigned code {0u};
		double price {0.0};

		// reads a line of data from the reference to an 
		// input file stream object
		bool load(std::ifstream& f) 
		{
			f >> code >> price;
			return f.good();
		}

		// inserts the data stored in the current price object 
		// into the reference to the ostream object in human-readable 
		// form
		void display(std::ostream& os) const 
		{
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string m_desc {};
		double m_price {0.0};
		int m_id {0};
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;

		// default constructor
		Product() 
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" 
					<< std::endl;
		}

		// Custom constructor
		Product(const std::string& str, double p) 
		{
			this->m_desc = str;
			this->m_price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" 
					<< std::endl;
		}

		// copy constructor
		Product(const Product& other) 
		{
			this->m_desc = other.m_desc;
			this->m_price = other.m_price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
					<< "] from [" << other.m_id << "]"
					<< std::endl;
		}

		// destructor
		~Product() 
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" 
					<< std::endl;
		}

		// TODO: add a function here to validate the price
		// this function throws an exception if the price is negative
		void validate() const 
		{
			if(this->m_price < 0)
				throw std::string("*** Negative prices are "
						"invalid ***");
		}

		// inserts the data stored in the current Product object 
		// into the reference to the ostream object in human-readable 
		// form
		void display(std::ostream& os) const 
		{
			os << std::setw(FWD) << m_desc
				<< std::setw(FWP) << m_price
				<< std::endl;
		}
	};
}
#endif // SDDS_ELEMENT_H
