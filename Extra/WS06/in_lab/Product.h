#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include "iProduct.h"

namespace sict {

	class Product : public iProduct {

		int num;
		float _price;

		public:
		Product(int n, float p);
		~Product();
		double price() const;
		void display(std::ostream& os) const;

	};

}

#endif
