#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <string>

namespace sict {

	class Text {

		unsigned no;
		std::string *strs;

		public:
		Text();
		Text(const char *);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;

	};

}

#endif
