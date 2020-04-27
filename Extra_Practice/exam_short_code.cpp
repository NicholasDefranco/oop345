#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>

// algorithm library includes the find_if() algorithm
#include <algorithm>

const int k = 10;

int main() {

	// this constructor allocates 5 elements to the vector immediately and
	// initializes each element with the value of 13
	std::vector<int> vector(5, 13);

	vector[3] = k;

	// I replaced auto with a const_iterator to show what's happning behind
	// the scenes...
	//
	// it will be assigned a const_iterator that points to the 
	// first element that satisfied the predicate (our lambda)
	std::vector<int>::const_iterator it = std::find_if
			(vector.cbegin(), vector.cend(), [](const int i) {
		// DO NOT CAPTURE GLOBAL VARIABLE k
		// It is illegal to capture variables of non-automatic 
		// storage duration. k is of static storage duration (it lasts
		// the lifetime of the program) 
		//
		// variables of automatic storage duration reside on the stack
		// they last from their declaration to the end of their scope
		return i == k;
	});

	// *it will give us the element the iterator is pointing to
	std::cout << std::setw(5) << *it << " found at index [" 
		// it - vector.begin() will calculate the number of types
		// between the two iterators
		<< it - vector.cbegin() << "]" << std::endl;

	return 0;

}
