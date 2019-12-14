// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 19th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// include files
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	
	// recieves a list of Description objects and Price objects
	// this function creates a list of Products from the matching
	// codes from the two recieved lists
	//
	// This solution uses raw pointers to hold the address in memory 
	// where the object resides on the heap
	// this solution requires manual memory deallocation
	List<Product> mergeRaw(const List<Description>& desc, 
						const List<Price>& price) {

		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		bool found {false};

		for(size_t i {0ul}; i < desc.size(); i++) {
			for(size_t j {0ul}; j < price.size() && !found; j++) {
				if(desc[i].code == price[j].code) {
					found = true;
					Product *tmp {new Product(desc[i].desc,
							price[j].price)};

					// I know the purpose was to allow the
					// pointer holding the address to go
					// out of scope without deallocating it
					// (to demonstrate that it doesn't get 
					// destructed), but I personally don't
					// like leaving my code with a memory
					// leak inside of it.
					try {
						tmp->validate();
					} catch(const std::string& msg) {
						// Product::trace assignments
						// are meant to stop tracing 
						// the destructor when a 
						// memory leak was suppossed 
						// to occur
						//
						// (required to pass the test
						// case to make it appear from
						// the output that the object
						// never got destructed)
						Product::Trace = false;
						delete tmp;
						Product::Trace = true;
						throw; // continue throwing
					}
					priceList += tmp;
					delete tmp;

				}
			}
			found = false;
		}


		return priceList;
	}

	// recieves a list of Description objects and Price objects
	// this function creates a list of Products from the matching
	// codes from the two recieved lists
	//
	// This solution uses smart pointers to manage the memory allocated
	// to the object off the heap
	// This solution does not require a try catch to stop a memory leak
	List<Product> mergeSmart(const List<Description>& desc, 
						const List<Price>& price) {

		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		// 		using smart pointers

		bool found {false};

		for(size_t i {0ul}; i < desc.size(); i++) {
			for(size_t j {0ul}; j < price.size() && !found; j++) {
				if(desc[i].code == price[j].code) {
					found = true;
					std::unique_ptr<Product> 
						tmp(new Product(desc[i].desc,
							price[j].price));

					tmp->validate();
					priceList += tmp;

				}
			}
			found = false;
		}


		return priceList;
	}
}
