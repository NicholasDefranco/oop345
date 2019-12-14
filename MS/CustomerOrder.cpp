// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, November 24th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

// complementary definition of class variable
// I have chosen the default width to be one
size_t CustomerOrder::width {1ul};

// recieves a unmodifiable reference to a string object which contains
// a record read in the file
//
// this constructor extracts the data from the string reference
// and stores the data into the data members
CustomerOrder::CustomerOrder(const std::string& str)
{
	bool more {true};
	size_t i {0ul};
	Utilities util {};
		
	name = util.extractToken(str, i, more);

	product = util.extractToken(str, i, more);

	no = std::count(str.begin() + i, str.end(), util.getDelimiter());
	
	// if the last character is not a delimiter that implies
	// there is one more field to count
	if(str[str.size() - 1] != util.getDelimiter())
		no++;

	ilist = new ItemInfo *[no];

	std::for_each(ilist, ilist + no, 
			[&util, &str, &i, &more](ItemInfo* &iteminfo) {
		iteminfo = new ItemInfo(util.extractToken(str, i, more));
	});


	if(width < util.getFieldWidth())
		width = util.getFieldWidth();

}

// copy constructor
// throws an exception in the event the client attempts to perform a 
// copy operation
CustomerOrder::CustomerOrder(const CustomerOrder& c)
{
	throw "Invalid operation";
}

// deallocates the resource the class manages
void CustomerOrder::clean() 
{

	std::for_each(ilist, ilist + no, [](ItemInfo *iteminfo) {
		delete iteminfo;
	});

	delete [] ilist;
}

// move operators
CustomerOrder::CustomerOrder(CustomerOrder&& c) noexcept
{
	*this = std::move(c);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c)
{

	if(this != &c) {

		clean();

		name = std::move(c.name);
		product = std::move(c.product);
		no = c.no;
		ilist = c.ilist;

		c.no = 0ul;
		c.ilist = nullptr;

	}

	return *this;
}

// destructor
CustomerOrder::~CustomerOrder()
{
	clean();
}

// returns the state of an item specified by name in the parameter
// if the item is non-existant the state is considered to be true
bool CustomerOrder::getItemFillState(const std::string& name) const
{

	return !std::any_of(ilist, ilist + no, [&name](const ItemInfo *item) {
		return item->name == name && !item->state;
	});

}

// returns true if all items in an order have been filled
bool CustomerOrder::getOrderFillState() const
{

	return std::all_of(ilist, ilist + no, [](const ItemInfo *iteminfo) {
		return iteminfo->state;
	});

}

// fills the item (if it exists) in the current order corresponding 
// to the item parameter
// this function reports a status message by inserting the message
// into the reference to an ostream object
void CustomerOrder::fillItem(Item& item, std::ostream& os) const
{
	std::for_each(ilist, ilist + no, 
				[this, &item, &os](ItemInfo *iteminfo) {
		if(iteminfo->name == item.getName()) {
			if(item.getQuantity() > 0) {
				item.updateQuantity();
				iteminfo->serial = item.getSerialNumber();

				iteminfo->state = true;

				os << "Filled "; 
			} else {
				os << "Unable to fill "; 
			}

			os << name << ", " << product << '[' << item.getName()
					<< ']' << std::endl;
		}
	});

}

// inserts the contents of the current order in human-readable form 
// into the reference to the ostream object recieved as parameter
void CustomerOrder::display(std::ostream& os) const 
{
	os << name << " - " << product << std::endl;
	std::for_each(ilist, ilist + no, [&os](const ItemInfo *item) {
		os << '[' << std::setfill('0') << std::setw(SERIAL_WIDTH) 
			<< item->serial << std::setfill(' ')
			<< "] " << std::setw(width) << std::left
			<< item->name << " - " << std::right
			<< (item->state ? "FILLED" : "MISSING")
			<< std::endl;
	});
}
