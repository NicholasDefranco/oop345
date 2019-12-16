#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H

#include <iostream>
#include <exception>

namespace sict {

	template<typename T>
	class KVList {
		T *arr = nullptr;	
		size_t size {0};
		size_t no {0};

		public:
		KVList() {

		}
		KVList(int n) {
			if(n > 0) {
				size = n;
				arr = new T[n];
			} 
		}
		KVList(KVList&& k) {
			arr = k.arr;
			no = k.no;
			size = k.size;

			k.size = 0;
			k.arr = nullptr;
			k.no = 0;
		}
		~KVList() {
			delete [] arr;
		}
		KVList(const KVList&) = delete;
		KVList& operator=(const KVList&) = delete;
		KVList& operator=(KVList&&) = delete;
		const T& operator[](size_t i) const {
			return arr[i];
		}
		bool isempty() const {
			return size <= 0;
		}
		template<typename F>
		void display(std::ostream& os, F f) const {
			if(!isempty()) {
				for(unsigned i = 0; i < no; i++) {
					arr[i].display(os, f);
					os << std::endl;
				}
			}
		}
		void push_back(const T& t) {
			if(no < size) {
				arr[no++] = t;
			}
		}
	};

}
#endif
