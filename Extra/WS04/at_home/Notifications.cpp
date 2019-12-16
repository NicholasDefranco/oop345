#include <iostream>
#include "Notifications.h"

namespace sict {

	Notifications::Notifications() {

	}

	Notifications::Notifications(size_t max) {
		if(max > 0) {
			this->arr = new const Message *[max];
			this->max = max;
		}
	}

	Notifications::Notifications(const Notifications& n) {
		delete [] this->arr;
		this->arr = new const Message *[n.no];
		for(unsigned i = 0; i < n.no; i++) {
			this->arr[i] = n.arr[i];
		}
		this->no = n.no;
		this->max = n.max;
	}

	Notifications::Notifications(Notifications&& n) {
		delete [] this->arr;
		this->arr = n.arr;
		this->no = n.no;
		this->max = n.max;

		n.arr = nullptr;
		n.no = 0;
		n.max = 0;
	}

	Notifications::~Notifications() {
		delete [] this->arr;
	}

	Notifications& Notifications::operator+=(const Message& msg) {
		if(!msg.empty() && this->no < this->max) {
			this->arr[no++] = &msg;	
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		for(unsigned i = 0; i < no && !found; i++) {
			if(arr[i] == &msg) {
				arr[i] = nullptr;
				found = true;
				for(unsigned j = i; j < no - 1; j++) {
					arr[j] = arr[j + 1];
				}
				no--;
			}
		}
		return *this;
	}

	void Notifications::display(std::ostream& os) const {
		for(unsigned i = 0; i < no; i++) {
			arr[i]->display(os);
		}
	}

	size_t Notifications::size() const {
		return no;
	}

	std::ostream& operator<<(std::ostream& os, const Notifications& n) {
		n.display(os);
		return os;
	}

}
