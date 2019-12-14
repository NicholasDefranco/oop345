// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 1st, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Note: extra parts were added for practicing purposes

// Header safeguards
#ifndef SDDS_LIST_H
#define SDDS_LIST_H

namespace sdds 
{

	template <typename T, unsigned N>
	class List {
	
		// Amount of elements currently stored in the array
		size_t no {0u};

		// Static array of any type with N elements
		T arr[N] {};

		public:
		// Defualt constructor
		// (extra)
		List() = default;

		// Rule of 3 (no move operators since all members are static)
		// (extra, not required for the assignment)
		// Copy constructor
		List(const List& l)
		{
			*this = l;
		}

		// Copy assignment operator
		List& operator=(const List& l) 
		{
			if(this != &l) {
				this->no = l.no;
				for(size_t i = 0u; i < no; i++) {
					this->arr[i] = l.arr[i];
				}
			}
			return *this;
		}

		// Destructor
		virtual ~List() = default;

		// Returns amount of elements in the array
		inline size_t size() const 
		{
			return no;
		}

		// Returns element at specified index
		inline const T& operator[](size_t i) const 
		{
			return arr[i];
		}
		
		// Adds element to list if it is not already full
		void operator+=(const T& tt) 
		{
			if(no < N)
				arr[no++] = tt;
		}

	};

	template<typename L, typename V, typename T, unsigned N>
	class LVList : public List<T, N> {
		public:
		// Using definitions of constructors that were not shawdowed
		// (extra)
		using List<T, N>::List;

		// Copy assignment operator
		// (extra)
		LVList& operator=(const LVList& l)
		{
			List<T, N>::operator=(l);
			return *this;
		}

		// Destructor
		// (extra)
		~LVList() override = default;

		// Returns the sum of all the values of the label-value pair
		// in the array
		V accumulate(const L& label) const
		{
			V accumulator = T::getInitialValue();
			for(unsigned i = 0; i < List<T, N>::size(); i++) {
				accumulator =
					(*this)[i].sum(label, accumulator);
			}
			return accumulator;
		}
	};

}

#endif // SDDS_LIST_H
