#include <iostream>
#include <iomanip>
#include <vector>
#include "Grocery.h"

using namespace std;
using namespace sict;

int FWPrice {5};
int FWDescription {10};

void loadCart(const char *userFile, vector<Grocery>& cart);

int main(int argc, char *argv[]) {
	cout << setprecision(2) << fixed;
	vector<Grocery> cart;
	loadCart(argv[1], cart);
	cout << "Items in Cart:" << endl;
	for(auto& e : cart) {
		e.display(cout);
	}

}
