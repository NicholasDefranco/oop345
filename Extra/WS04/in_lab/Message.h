#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>	
#include <string>

namespace sict {

	class Message {

		std::string sent;
		std::string reply;
		std::string msg;

		public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;

	};

}

#endif
