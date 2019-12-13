#include <iostream>
#include <chrono> //allows us to use milliseconds
#include <thread> //allows for the sleep_for function

int blastOff(int i) {
	if (i > 0) { //Our exit condition
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));//wait a second

		//calling blast function while decreasing our variable
		//our current blast off gets added to the stack until we resolve all of them. 
		blastOff(--i);
	}
	else
	{
		//we blast off
		std::cout << "Blast Off!!!  WOOOSH" << std::endl;
		return 0; //return control to our main application
	}
}


int main() {
	int count = 10;
	blastOff(count);//invoke for the first time
	std::cin.get();
	return 0;
}
