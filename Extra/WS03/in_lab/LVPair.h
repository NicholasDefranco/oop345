#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>

namespace sict {

	template<typename L, typename V>
	class LVPair {

		L label;
		V value;
		bool empty;

		public:

		LVPair() : empty(true) { }

		LVPair(const L& label, const V& value) : empty(false) {
			this->label = label;
			this->value = value;
		}

		void display(std::ostream& os) const {
			if(!empty) {
				os << label << " : " << value << std::endl;
			}
		}

	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

}

#endif
