// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, December 1st, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safe guards
#ifndef LINEMANAGER_H
#define LINEMANAGER_H

// include files
#include <iostream>
#include <vector>
#include <deque>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager {

	std::vector<Task *> line;
	std::deque<CustomerOrder> process;
	std::deque<CustomerOrder> complete;
	size_t total_orders {0ul};

	// keeps track of the current size of the complete deque
	size_t complete_cnt {0ul};

	Task *first {nullptr};

	public:
	// custom 3-arg constructor
	// receives the name of the file, vector of pointers to task objects,
	// and a vector of CustomerOrder objects
	//
	// reads the file to determine what the next task is for each task
	// in the vector
	//
	// contents of each CustomerOrder object within the vector p is moved
	// onto the process queue(to be filled queue)
	//
	// each Task * element within the l vector is copied onto the line 
	// vector(Assembly line)
	LineManager(const std::string& file, std::vector<Task *>& l, 
			std::vector<CustomerOrder>& p);

	// runs one process cycle
	// moves the last order on the process queue onto the start of the 
	// assembly line(if any)
	//
	// runs a cycle for each Task on the assembly line
	//
	// moves the last order to the next task on the line(if task completed)
	//
	// returns true if all orders have been filled
	bool run(std::ostream& os);

	// inserts all CustomerOrder data stored in each completed order
	// into the reference to an ostream object
	void displayCompleted(std::ostream& os) const;

	// validates each task on the line
	void validateTasks() const;

};

#endif // LINEMANAGER_H
