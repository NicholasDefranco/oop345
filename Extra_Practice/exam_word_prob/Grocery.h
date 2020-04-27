#ifndef SICT_GROCERY_H
#define SICT_GROCERY_H

#include <iostream>
#include <string>

namespace sict {

	class Grocery {
		std::string desc;
		double price;
		std::string tax;

		public:
		Grocery(std::string d, double p, std::string t);

		// deleted copy operations
		Grocery(const Grocery& g) = delete;
		Grocery& operator=(const Grocery& g) = delete;

		Grocery(Grocery&& g);
		Grocery& operator=(Grocery&& g);

		void display(std::ostream& os);
	};

}

#endif
