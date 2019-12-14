#include <iostream>
#include <vector> //allows us to use vectors
#include <algorithm> //allows for sorting and counting of vectors
#include <numeric> //allows for numerical mathematics on vectors

using namespace std;

int main() {
	std::vector<int> myNums{123, 6, 8, 23, 45, 3, 11, 10, 44, 9, 100, 15, 18};	


	cout << "orig vector: ";
	for (auto i = myNums.begin(); i != myNums.end(); i++)
		cout << *i<< " ";
	cout << endl;

	//Question 1 uncomment to work on it.
	//-----------------------------------------------------------------------------------------------
	//Here I have a vector,  I want you to count how many even numbers
	//that are smaller than 19 in it and store the results in "result" 
	//YOU SHOULD GET "4"
	int result = count_if(myNums.cbegin(), myNums.cend(), [](int n) {
		return n % 2 == 0 && n < 19;
	});

	cout << "results are: " << result << endl;

	//Question 2 uncomment to work on it.
	//-----------------------------------------------------------------------------------------------
	// I want you to find the average of all odd numbers that are smaller 
	// than 40 YOU SHOULD GET "12.2"
	// Hint, I reccomend copying to a new vector for this 
	// (USE 2 Algorithm funtions)

	int count = 0; //keeps track of how many numbers meet condition

	vector<int> newVec(myNums.size()); //sets the size. If we try to move 
	// it without being initialized we get errors

	copy_if(myNums.begin(), myNums.end(), newVec.begin(), [&count](int n) {
		if (n % 2 == 1 && n < 40) {
			count++;
			return true;
		}
		else
		return false;
	});

	//this loop checks to see if your above algoritm pulls the correct data
	for (auto i = newVec.begin(); i != newVec.end(); i++)
		cout << *i<<endl;
	

	double average = 
		double(accumulate(newVec.begin(), newVec.end(), 0.0)) / count;

	cout << "average is: " << average << endl;

	//Question 3 COMPLETE THE CODE
	//-----------------------------------------------------------------------------------------------
	//My Vector is very messy please sort it in descending order (USE 1 Algorithm funtion)

	cout << "Question 3: messy vector: ";
	for (auto i = myNums.begin(); i != myNums.end(); i++)
		cout << *i<< " ";
	cout << endl;
	//add your code here
	std::sort(myNums.begin(), myNums.end(), [](int a, int b) {
		return a > b; 
	});

	//-----------
	cout << "sorted vector: ";
	for (auto i = myNums.begin(); i != myNums.end(); i++)
		cout << *i << " ";
	cout << endl<<"-----------------------------------------------------------------------------------------------"<<endl;

	//Question 4 Complete the code
	//-----------------------------------------------------------------------------------------------
//replace all instances of numbers that are divisible by 3 with -1 (USE 1 Algorithm funtion)
	
	//add code here:
	replace_if(myNums.begin(), myNums.end(), [](int n) {
		return n % 3 == 0;
	}, -1);

	cout << "Question 4: replaced vector: ";
	for (auto i = myNums.begin(); i != myNums.end(); i++)
		cout << *i << " ";
	cout << endl;



	//Question 5 uncomment to work on it.  
	//-----------------------------------------------------------------------------------------------
	//Check to see if any values are even and divisible by 30

	if (any_of(myNums.begin(), myNums.end(), [](int n) {
		return n % 30 == 0;
	})) {
		cout << "We found a match" << endl;

	}
	else {
		cout << "None meet the criteria" << endl;
	}

	return 0;

}
