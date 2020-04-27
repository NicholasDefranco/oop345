#include <fstream>
#include <iostream>
#include <vector>
#include "Grocery.h"

using namespace std;
using namespace sict;

void loadCart(const char *filename, vector<Grocery>& cart) {

	ifstream file(filename);
	if(!file) exit(1);
	while(file) {
		string description;
		double price;
		string tax = " ";
		file >> description >> price;
		bool isTaxed = file.get() != '\n';
		if(isTaxed)
			file >> tax;

		try {
			cart.push_back(Grocery(description, price, tax));
		} catch (const char *msg) {
			cerr << msg << " : " << description << " " << price
				<< " " << tax << std::endl;
		}
	}

}
