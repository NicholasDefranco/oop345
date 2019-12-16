#include <iostream>
#include <cstring>
#include <chrono>
#include "Timekeeper.h"

using namespace std;

namespace sict {

	Timekeeper::Timekeeper() { }

	Timekeeper::~Timekeeper() {
		for(unsigned i = 0; i < no; i++) {
			delete [] records[i].msg;
			delete [] records[i].unit;
		}
	}

	void Timekeeper::start() {
		strt = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop() {
		endt = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char *desc) {
		unsigned len {static_cast<unsigned>(strlen(desc))};
		records[no].msg	= new char[len + 1];
		strcpy(records[no].msg, desc);

		records[no].duration = endt - strt;

		len = strlen("seconds");
		records[no].unit = new char[len + 1];
		strcpy(records[no].unit, "seconds");

		no++;
	}

	void Timekeeper::report(ostream& os) const {
		os << "Execution Times:" << endl;
		for(unsigned i {0U}; i < no; i++) {
			os << records[i].msg << '\t' << 
			chrono::duration_cast<chrono::seconds>(records[i].duration).count() << ' ' 
			<< records[i].unit << endl;
		}
	}
		

}
