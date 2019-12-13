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
		~Product() = default;
		double price() const;
		void display(std::ostream& os) const;

	};

	enum class type {
		HST,
		PST
	};

	class TaxableProduct : public Product {
		
		type status;

		public:
		TaxableProduct(int n, float p, type s);
		~TaxableProduct() = default;
		double price() const;
		void display(std::ostream& os) const;

	};

}

#endif
