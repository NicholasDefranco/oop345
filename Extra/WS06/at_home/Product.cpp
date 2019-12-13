#include <iostream>
#include <iomanip>
#include "Product.h"

namespace sict {

	Product::Product(int n, float p) : num(n), _price(p) { }

	double Product::price() const {
		return this->_price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << num << std::setw(10) << _price;
	}

	TaxableProduct::TaxableProduct(int n, float p, type s) : Product(n, p),
							status(s) { } 

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << ' ' << (status == type::HST ? 'H' : 'P');
	}

	double TaxableProduct::price() const {
		return Product::price() * (status == type::HST ? 1.13 : 1.08);
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct *readRecord(std::ifstream& file) {

		sict::iProduct *p = nullptr;
		int tnum;
		float tprice;

		file >> tnum;
		if(file.good()) {
			file >> tprice;
		}

		if(file.good()) {
			if(file.get() != '\n') {
				char tmp = file.get();
				if(tmp == 'H') {
					p = new sict::TaxableProduct(tnum, 
						tprice, type::HST);
				} else {
					p = new sict::TaxableProduct(tnum, 
						tprice, type::PST);
				}
			} else {
				p = new sict::Product(tnum, tprice);
			}
		}

		return p;
	}

}
