#ifndef SICT_SALE_H
#define SICT_SALE_H

#include <iostream>
#include <deque>
#include "iProduct.h"

namespace sict {
	
	class Sale {

		std::deque<iProduct *> arr;
		
		public:
		Sale(const char *fname);
		~Sale();
		void display(std::ostream& os) const;

	};

}

#endif
