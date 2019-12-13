#include <iostream>
#include <iomanip>
#include "Product.h"

namespace sict {

	Product::Product(int n, float p) : num(n), _price(p) { }

	double Product::price() const {
		return this->_price;
	}

	Product::~Product() {
		
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << num << std::setw(10) << _price;
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
			file.ignore();
		}

		if(file.good()) {
			p = new sict::Product(tnum, tprice);
		}

		return p;
	}

}
