#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>
#include <typeinfo>
#include "LVPair.h"

namespace sict {

	template<typename T, int N>
	class List {
		T arr[N];
		size_t no = 0;	

		public:
		size_t size() const {
			return no;
		}

		const T& operator[](size_t i) const {
			return arr[i];
		}

		void operator+=(const T& t) {
			if(no < N) {
				arr[no++] = t;
			}
		}

	};

	template<typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {

		public:
		V accumulate(const L& label) const {
			V s = SummableLVPair<L, V>::getInitialValue();	
			for(unsigned i = 0; i < this->size(); i++) {
				s = (*this)[i].sum(label, s);
			}
			return s;
		}
	};

}

#endif
