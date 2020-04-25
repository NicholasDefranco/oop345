#include <iostream>
 #define PI/**/3.14
 #define SQUARE(X)  ((X) * (X))

#undef PI

#if defined(PI)

#error "Don't do that"

#endif

#define PI

#if defined(PI)

#error "wow"

#endif

int factorial(int num) {

	if(num == 1) {
		return num;
	}

	return factorial(num - 1) * num;
}

int factorial2(int num) {

	int total = 1;

	while(num > 0) {
		total *= num--;
	}

	return total;
}

int main() {
	double r = 2.35;
//	std::cout << "PI(r++)^2 is " << PI * SQUARE(++r) << std::endl; 
	std::cout << "r is now " << r << std::endl;
	std::cout << factorial2(4) << std::endl;
}

