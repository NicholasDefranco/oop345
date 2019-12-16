#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include <iostream>
#include <iomanip>

namespace sict {

	template<typename K, typename V>
	class KVPair {

		K key;
		V value;
		bool empty {true};

		public:
		KVPair() { }
		KVPair(const K& key, const V& value) : empty(false) {
			this->key = key;
			this->value = value;
		}

		template<typename F>
		void display(std::ostream& os, F f) const {
			if(!empty) {
				os << std::left << std::setw(10) << key 
				<< " : " << std::right
				<< std::setw(10) << value 
				<< std::setw(10) << f(value);
			}
		}

	};

}

#endif
