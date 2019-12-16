#ifndef SICT_LIST_H
#define SICT_LIST_H

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

}

#endif
