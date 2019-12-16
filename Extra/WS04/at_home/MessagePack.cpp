#include <iostream>
#include "MessagePack.h"

namespace sict {

	MessagePack::MessagePack() {
		
	}

	MessagePack::MessagePack(Message **msgs, size_t size) {
		if(msgs != nullptr && size > 0) {
			this->msgs = new Message[size];
			for(unsigned i = 0; i < size; i++) {
				this->msgs[i] = *(msgs[i]);
			}
			this->siz = size;
		} 
	}

	MessagePack::MessagePack(const MessagePack& p) {
		delete [] this->msgs;
		this->msgs = new Message[p.siz];
		for(unsigned i = 0; i < p.siz; i++) {
			this->msgs[i] = p.msgs[i];
		}
		this->siz = p.siz;
	}

	MessagePack::MessagePack(MessagePack&& p) {
		delete [] this->msgs;
		this->msgs = p.msgs;
		this->siz = p.siz;

		p.msgs = nullptr;
		p.siz = 0;
	}

	MessagePack::~MessagePack() {
		delete [] this->msgs;
	}

	void MessagePack::display(std::ostream& os) const {
		for(unsigned i = 0; i < this->siz; i++) {
			msgs[i].display(os);
		}
	}

	size_t MessagePack::size() const {
		return siz;
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack& p) {
		p.display(os);
		return os;
	}

}
