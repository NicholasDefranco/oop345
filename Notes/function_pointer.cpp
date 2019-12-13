#include <iostream>

void desc(int *a1, int s1) {  //This function loops backwards and prints each element
	for (int i = s1-1; i != -1; i--) {
		std::cout << "#" << a1[i] << std::endl;
	}
}

void asc(int *a1, int s1) { //This function loops forward and prints each element
	for (int i = 0; i<s1; i++) {
		std::cout << "#" << a1[i] << std::endl;
	}
}

//takes an array reference, size of the array, and a pointer to a function.
void print(int* arr, int size, void(*order)(int *a1, int s1)) {
	order(arr, size); //call whichever function gets passed in
}


int main() {
	int a[] = { 1, 2,3,4,5,6,7,8,9,10 };

	std::cout << "Ascending order:" << std::endl << "__________________" << std::endl;
	print(a,10,asc); //passes the asc function as an argument

	std::cout << std::endl;

	std::cout << "Descending order:" << std::endl << "__________________" << std::endl;
	print(a, 10, desc); //passes the desc function as an argument
	std::cin.get();
	return 0;
}
