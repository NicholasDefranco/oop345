// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 19th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// include files
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {

    template <typename T>
    class List {
		std::vector<T> list;

		public:
		// default constructor
		List() = default;

		// custom one-arg constructor
		// reads the contents of file fn and populates the container
		// data member with data that was read
		List(const char* fn) 
		{
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") 
					+ std::string(fn) 
					+ std::string(" ***");

			while (file) {
				T e;
				if (e.load(file)) {
					list.push_back(std::move(e));
				}
			}
		}

		// returns the size of the container
		size_t size() const 
		{ 
			return list.size(); 
		}

		// returns a unmodifiable reference to an element in the 
		// container
		const T& operator[](size_t i) const 
		{ 
			return list[i]; 
		}

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		//
		// Recieves the address of an object
		// moves the object stored at that address into the container
		void operator+=(T *elem)
		{
			// (NOTES) instructions specify to move the object 
			// into the container at the address stored in 
			// the parameter
			//
			// however, the product class does not define move
			// operators. Therefore, passing a rvalue reference
			// to push_back() has to effect. The runtime
			// will still call the copy constructor
			list.push_back(std::move(*elem));
		}

		// TODO: Overload the += operator with a smart pointer
		// 		as a second operand.
		//
		// Recieves a reference to a smart pointer that manages a 
		// object (resource) of type T
		//
		// moves the object stored at that address the referenced
		// smart pointer manages into the container
		void operator+=(std::unique_ptr<T>& elem) 
		{
			// read note in other overload
			list.push_back(std::move(*elem));
		}

		// inserts the data stored in each element stored in the list 
		// object into the reference to the ostream object in 
		// human-readable form
		void display(std::ostream& os) const 
		{
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.display(os);
		}
	};

	// inserts the data stored in each element in the list object into the 
	// reference to the ostream object in human-readable form
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l) 
	{
		l.display(os);
		return os;
	}
}
#endif // SDDS_LIST_H
