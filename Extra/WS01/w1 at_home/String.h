#ifndef SICT_STRING_H
#define SICT_STRING_H

#include <iostream>

namespace sict {

	const int MAX = 3;

	class String {

		char *str;	

		public:
		String(const char *);
		~String();
		std::ostream& display(std::ostream&) const;



	};

	std::ostream& operator<<(std::ostream&, const String&);

}

#endif
