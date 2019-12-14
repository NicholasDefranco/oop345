// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

// include files
#include <iostream>
#include <string>
#include <stdexcept>

namespace sdds 
{
	template<typename T>
	class Collection {

		// title of collection
		std::string name {};

		// array of generic type
		T *arr {nullptr};
		// size of array
		size_t no {0u};

		// function pointer
		void (*func)(const Collection<T>&, const T&) {nullptr};

		public:
		// one-arg constructor
		// sets the name of the object to the parameter
		Collection(std::string n) 
		{
			this->name = n;
		}

		// This class doesn't support copy operations
		Collection(const Collection<T>&) = delete;
		Collection& operator=(const Collection<T>&) = delete;
		Collection(Collection<T>&&) = delete;
		Collection& operator=(Collection<T>&&) = delete;

		// destructor
		~Collection() 
		{
			delete [] arr;
		}

		// accessors
		const std::string& get_name() const noexcept
		{
			return name;
		}
		// returns the size of the array
		size_t size() const noexcept
		{
			return no;
		}

		// stores the parameter into an attribute, to be used when an
		// item is added to the collection. 
		void setObserver(void (*observer)
				(const Collection<T>&, const T&)) noexcept
		{
			func = observer;
		}

		
		// adds a copy of item into the array if array doesn't
		// already have an element with the same title
		Collection<T>& operator+=(const T& item) 
		{
			bool found {false};
			for(size_t i {0u}; i < no && !found; i++) {
				if(item.gettitle() == arr[i].gettitle()) {
					found = true;
				}
			}

			if(!found) {
				T *tmp = new T[no + 1];
				for(size_t i {0u}; i < no; i++) {
					tmp[i] = arr[i];
				}
				tmp[no++] = item;
				delete [] arr;
				arr = tmp;
				if(func != nullptr) {
					func(*this, item);
				}
				tmp = nullptr;
			}
			return *this;
		}

		// returns the element at specified index the the parameter
		// throws std::out_of_range exception 
		// in the event of the client passing a bad index
		T& operator[](size_t i) const
		{
			if(i < 0 || i >= no) {
				throw std::out_of_range("Bad index [" 
					+ std::to_string(i) + "]. " 
					+ "Collection has ["
					+ std::to_string(no) + "] items.");
			}
			return arr[i];
		}

		// returns the address of the element with the same 
		// title as the title recieved in the parameter list
		// returns nullptr if title doesn't exist in the array
		T *operator[](const std::string& title) const
		{
			T *tmp = nullptr;
			for(size_t i {0u}; i < no && tmp == nullptr; i++) {
				if(arr[i].gettitle() == title) {
					tmp = arr + i;
				}
			}
			return tmp;
		}
	};
	
	// inserts data stored in the object to the output stream
	// in a human-readable format
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c)
	{
		for(size_t i {0u}; i < c.size(); i++) {
			os << c[i];
		}
		return os;
	}
}

#endif // SDDS_COLLECTION_H
