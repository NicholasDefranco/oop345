#ifndef SICT_IPRODUCT_H
#define SICT_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace sict {

	class iProduct {

		public:
		virtual double price() const = 0;
		virtual ~iProduct() = default;
		virtual void display(std::ostream& os) const = 0;

	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);

	iProduct *readRecord(std::ifstream& file);

}

#endif
