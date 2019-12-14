// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, November 24th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safe guards
#ifndef ITEM_H
#define ITEM_H

// include files
#include <iostream>
#include <string>

// used in display function for formatting
const int SERIAL_WIDTH {6};

class Item {

	std::string name {};
	std::string desc {};
	unsigned serial {0u};
	unsigned no {0u};

	// since all instances of the class share the same width
	// the member storing the width must be a class variable(static
	// variable)
	static size_t width; 
	
	public:
	// recieves an unmodifiable reference to a string object which contains
	// a record that was read from the file
	//
	// this constructor extracts the data from the string reference
	// and stores the data into the data members
	explicit Item(const std::string& str);

	// returns unmodifiable reference to the name of the current object
	const std::string& getName() const noexcept;

	// returns next available serial number
	const unsigned getSerialNumber();

	// returns the amount of the current item in stock
	const unsigned getQuantity() const noexcept;

	// updates quantity
	void updateQuantity();

	// inserts the contents of the current item object in human-readable 
	// form into the reference to the ostream object recieved as the first
	// parameter
	// 
	// also receives a bool specifing how much information to is to be
	// inserted
	void display(std::ostream& os, bool full) const;

};

#endif // ITEM_H
