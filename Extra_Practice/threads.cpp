#include <iostream>
#include <thread>  //TODO: add library for threading
/*
If you are having trouble running on VS you might have to switch your complier to c++17 
Here are instructions to do so https://stackoverflow.com/questions/41308933/how-to-enable-c17-compiling-in-visual-studio

*/

void task1(int x) {
	std::cout << "Thread: " << x << " Says Hi!"<< std::endl; 
}

//TODO: Create a thread variable of type "int" here called "threadVar" and assign it to "1"
thread_local int threadVar = 1;

void task2() {
	std::cout <<"threadVar: "<< threadVar++ << std::endl;
}




int main() {
	//Q1: Make 2 threads using task1 above to print the expected output below:
	/*Expected Output
	Thread: 1 Says Hi!
	Thread: 2 Says Hi!
	*/

	std::thread t1(task1, 1);

	t1.join();
	std::thread t2(task1, 2);
	t2.join();


	//-----------------------------------------------------------------------------------------------
	//Q2:Follow the steps, and match the expected output below:
	/*Expected Output:
	threadVar: 1
	1
	threadVar: 1
	2
	*/


	//1. create a thread that calls task2
	std::thread t3(task2);

	t3.join();
	//2. Post_Increment the threadVar by 1 and put the result in a cout;

	std::cout << threadVar++ << std::endl;
	//3. create a thread that calls task2
	std::thread t4(task2);	

	t4.join();
	//4. Post_Increment the threadVar by 1 and put the result in a cout;
	
	std::cout << threadVar++ << std::endl;
	//-----------------------------------------------------------------------------------------------


	std::cin.get();
	return 0;
}
