#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace sict {

	Text::Text() : no(0) {
		strs = nullptr;
	}

	Text::Text(const char *fname) : no(0) {
		strs = nullptr;
		std::fstream f(fname, std::ios::in);
		while(!f.eof()) {
			if(f.get() == '\n') {
				no++;	
			}
		}

		f.clear();

		if(no > 0) {
			strs = new std::string[no];
			f.seekg(0);
			for(unsigned i = 0; i < no; i++) {
				getline(f, strs[i]);
			}
		}

		f.close();
	}

	Text::Text(const Text& t) {
		strs = nullptr;
		*this = t;
	}

	Text& Text::operator=(const Text& t) {
		if(this != &t) {
			delete [] strs;
			no = t.no;
			if(no > 0) {
				strs = new std::string[no];
				for(unsigned i = 0; i < no; i++) {
					strs[i] = t.strs[i];
				}
			} else {
				strs = nullptr;
			}
		}
		return *this;
	}

	Text::Text(Text&& t) {
		strs = nullptr;
		*this = std::move(t);
	}

	Text& Text::operator=(Text&& t) {
		if(this != &t) {
			delete [] strs;	
			no = t.no;
			strs = t.strs;

			t.no = 0U;
			t.strs = nullptr;
		}
		return *this;
	}

	Text::~Text() {
		delete [] strs;
	}

	size_t Text::size() const {
		return no;
	}

}
