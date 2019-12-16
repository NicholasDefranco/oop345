#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict {
	
	class Notifications {
		
		const Message **arr = nullptr;
		size_t no {0};
		size_t max {0};

		public:
		Notifications();
		Notifications(size_t max);
		Notifications(const Notifications& n);
		Notifications(Notifications&& n);
		~Notifications();
		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;

	};

	std::ostream& operator<<(std::ostream& os, const Notifications& n);

}

#endif
