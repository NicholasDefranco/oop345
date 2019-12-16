#ifndef MESSAGE_PACK_H
#define MESSAGE_PACK_H

#include <iostream>
#include "Message.h"

namespace sict {

	class MessagePack {

		Message *msgs = nullptr;
		size_t siz = 0;

		public:
		MessagePack();
		MessagePack(Message **msgs, size_t size);
		MessagePack(const MessagePack& p);
		MessagePack(MessagePack&& p);
		~MessagePack();
		void display(std::ostream& os) const;
		size_t size() const;

	};

	std::ostream& operator<<(std::ostream& os, const MessagePack& p);

}

#endif
