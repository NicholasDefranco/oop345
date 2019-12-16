#include <iostream>
#include "process.h"

using namespace std;
using namespace sict;


int main(int argc, char **argv) {
	
	if(argc < 2) {
		cout << "***Insufficient number of arguments***" << endl;
		return 1;
	}

	int i = 1;
	while(i < argc) {
//		cout << i + INITIAL - 1 << ": ";	
		process(argv[i]);
		i++;
	}

	return 0;
}
