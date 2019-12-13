#include <iostream>

int main() {
	int x = 5;
	int divisor = 0;

	std::cout << "Please enter a divisor number (try 0, tee hee): ";
	std::cin >> divisor;
	std::cin.get();//clears pesky newline char on windows.
	try {
		if (divisor!=0) std::cout << "5/"<<divisor<<"=" << (double)x/divisor << std::endl;
		else throw divisor;
	}
	catch (...) {
		std::cout << "Numbers cannot be divided by 0"<< std::endl;
		std::cout << "We have to do the check ourselves c++ doesn't allow division by 0." << std::endl;
		return 1; //end with specific error
	}
	std::cout << "Press enter to quit:";
	std::cin.get();

	return 0;
}
