// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, November 24th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safe guards
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

// include files
#include <iostream>
#include <string>
#include "Item.h"

// provided by the professor
// class that defines an item within a customer's order
struct ItemInfo
{
	std::string name {};
	unsigned int serial {0u};
	bool state {false};

	ItemInfo(std::string src) : name(src) {};
};

class CustomerOrder 
{

	std::string name {};
	std::string product {};
	size_t no {0ul};
	ItemInfo **ilist {nullptr};

	// since all instances of the class share the same width
	// the member storing the width must be a class variable(static
	// variable)
	static size_t width;

	// deallocates the resource associated with the class
	void clean();

	public:
	// default constructor
	CustomerOrder() = default;

	// recieves an unmodifiable reference to a string object which contains
	// a record that was read from the file
	//
	// this constructor extracts the data from the string reference
	// and stores the data into the data members
	CustomerOrder(const std::string& str);

	// copy operators
	// throws an exception in the event the client attempts to perform a 
	// copy operation
	CustomerOrder(const CustomerOrder&);
	CustomerOrder& operator=(const CustomerOrder&) = delete;

	// move operators
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);

	// destructor
	~CustomerOrder();

	// returns the state of an item specified by name in the parameter
	// if the item is non-existant the state is considered to be true
	bool getItemFillState(const std::string& item) const;

	// returns true if all items in an order have been filled
	bool getOrderFillState() const;

	// fills the item (if it exists) in the current order corresponding 
	// to the item parameter
	// this function reports a status message by inserting the message
	// into the reference to an ostream object
	void fillItem(Item& item, std::ostream& os = std::cout) const;

	// inserts the contents of the current order in human-readable form 
	// into the reference to the ostream object recieved as parameter
	void display(std::ostream& os = std::cout) const;

};

#endif // CUSTOMERORDER_H
