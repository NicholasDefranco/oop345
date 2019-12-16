#include <iostream>
#include <string>
#include "Message.h"

namespace sict {

	Message::Message() {

	}

	Message::Message(const std::string& str) {

		std::size_t found = 0;

		found = str.find_first_of(' ');

		if(found != std::string::npos) {

			sent = str.substr(0, found);

			if(str[++found] == '@') {
				std::size_t prev = found;
				found = str.find_first_of(' ', found);
				reply = str.substr(prev + 1, found - prev);
				found++;
			}

			msg = str.substr(found, std::string::npos - 1);

		}

	}
	
	inline bool Message::empty() const {
		return msg.empty();
	}

	void Message::display(std::ostream& os) const {
		if(!empty()) {
			os << ">User  : " << sent << std::endl;
			if(!reply.empty()) {
				os << " Reply : " << reply << std::endl;
			}
			os << " Tweet : " << msg << std::endl;
		}
	}

}
