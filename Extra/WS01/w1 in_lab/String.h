#ifndef SICT_STRING_H
#define SICT_STRING_H

#include <iostream>

namespace sict {

	const int MAX = 3;

	class String {

		char str[MAX + 1];	

		public:
		String(const char *);
		std::ostream& display(std::ostream&) const;



	};

	std::ostream& operator<<(std::ostream&, const String&);

}

#endif
