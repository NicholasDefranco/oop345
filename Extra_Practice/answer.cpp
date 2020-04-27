#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iterator>

int main() {

	int array1[] {16, 2, 27, 99, 100, 0, 55, 3, 4, 90, 8};

	std::vector<int> vect1(array1, array1 + sizeof(array1) / sizeof(int));

	std::vector<int> vect2;

	vect1.push_back(500);

	for(auto it {vect1.cbegin()}; it != vect1.cend(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::copy(vect1.cbegin(), vect1.cend(), 
		std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;

	std::copy(vect1.cbegin(), vect1.cend(), std::back_inserter(vect2));

	std::cout << "count " << std::count_if(vect1.cbegin(), vect1.cend(), [](const int i) {
		return i > 50 && i < 150;
	}) << std::endl;

	int total = 0;

	int count = std::count_if(vect1.cbegin(), vect1.cend(), [&total](const int i) {
		if(i > 20 && i < 99) {
			total += i;
			return true;
		} else {
			return false;
		}
	});

	std::cout << ((double)total / count) << std::endl;


	return 0;
}
