#include <iostream>
#include <iomanip>
#include <fstream>
#include "Sale.h"
#include "iProduct.h"

namespace sict {

	Sale::Sale(const char *fname) {
		iProduct *tmp = nullptr;
		std::ifstream f(fname);
		if(!fname) {
			throw "error opening file";
		}

		while(f) {
			tmp = readRecord(f);
			if(tmp != nullptr) {
				arr.push_back(tmp);
			}
		}
	}

	Sale::~Sale() {
		for(int i = 0; i < arr.size(); i++) {
			delete arr[i];
		}
	}

	void Sale::display(std::ostream& os) const {
		std::cout << "Product No" << std::setw(10)
		<< "Cost" << std::endl;
		for(int i = 0; i < arr.size(); i++) {
			os << *(arr[i]) << std::endl;
		}
	}

}
