#include <iomanip>
#include "Grocery.h"

// FWPrice and FWDescription have external linkage, they refer to another
// entity declared in another scope in another translation unit(or module)
// 
// These two statements are basically saying "FWPrice and FWDescription exist
// in some other cpp file, go find them and give me full read/write access to
// them"
extern int FWPrice;
extern int FWDescription;

namespace sict {

	Grocery::Grocery(std::string d, double p, std::string t) {
		// Although required, I doubt that they checked if students 
		// put that extra check that is checking for a space
		// as the instructions neglect the fact that a space for tax
		// (no tax) is also valid data
		if(t[0] != 'H' && t[0] != 'P' && t[0] != ' ')
			throw "*unlisted tax symbol*";

		desc = d;
		price = p;
		tax = t;
	}

	Grocery::Grocery(Grocery&& g) {
		*this = std::move(g);
	}

	Grocery& Grocery::operator=(Grocery&& g) {
		if(this != &g) {
			// don't forget to call the move assignment operator
			// on your std::string's
			desc = std::move(g.desc);
			price = g.price;
			tax = std::move(g.tax);
		}
		return *this;
	}


	void Grocery::display(std::ostream& os) {
		os << std::left << std::setw(FWDescription) << desc 
			<< std::right << std::setw(FWPrice) << price 
			<< " " << tax << std::endl;
	}

}
