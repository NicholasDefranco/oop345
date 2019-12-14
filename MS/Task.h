// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, December 1st, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safe guards
#ifndef TASK_H
#define TASK_H

// include files
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"

class Task : public Item {

	std::deque<CustomerOrder> orders;
	Task *next {nullptr};

	public:
	// recieves a unmodifiable reference to a string object which contains
	// a record read in the file
	//
	// this constructor extracts the data from the string reference
	// and stores the data into the data members
	explicit Task(const std::string& str);

	// deleted copy and move operations
	// a task can only ever appear once on an assembly line
	Task(const Task&) = delete;
	Task& operator=(const Task&) = delete;
	Task(Task&&) = delete;
	Task& operator=(Task&&) = delete;

	// completes a task on the order at the back of the queue
	void runProcess(std::ostream& os = std::cout);

	// moves an order to the next task on the assembly line only if the
	// task has been complete and not already at the end
	bool moveTask();

	// (extra)
	// returns the address of a unmodifiable task object
	// required for determining the first task in the assembly line
	const Task *getNextTask() const;

	// sets the next task to be the address of the parameter
	void setNextTask(Task& t);

	// sets the paramter to the last customer order in the queue 
	// and removes it from the queue
	// returns true on success
	bool getCompleted(CustomerOrder& c);

	// inserts the name of the current task as well as the next task
	// into the reference to an output stream object in human-readable
	// format
	void validate(std::ostream& os = std::cout) const;

	// moves the paramter onto the front of the customer order queue
	Task& operator+=(CustomerOrder&&);

};

#endif // TASK_H
