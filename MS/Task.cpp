// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, December 1st, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <iostream>
#include <deque>
#include "Task.h"

// recieves a unmodifiable reference to a string object which contains
// a record read in the file
//
// this constructor extracts the data from the string reference
// and stores the data into the data members
Task::Task(const std::string& str) : Item(str) { }

// completes a cycle of a task on the order at the back of the queue
void Task::runProcess(std::ostream& os)
{

	CustomerOrder& c = orders.back();
	if(!orders.empty() && !c.getItemFillState(getName())) {
		c.fillItem(*this, os);
	}
}

// moves an order to the next task on the assembly line only if the
// task has been complete and not already at the end
//
// based on a suggestion by you to another student on slack, this function
// should only return true if the current task has been filled and is the last
// task of the assembly line
bool Task::moveTask()
{

	bool success {false};

	CustomerOrder& c = orders.back();
	if(!orders.empty() && c.getItemFillState(getName())) {
		if(next) {
			*next += std::move(c);
			orders.pop_back();
		} else {
			success = true;
		}
	}

	return success;

}


// returns the address of a unmodifiable task object
// extra function that's required in linemanager to determine 
// the start of the assembly line
const Task *Task::getNextTask() const 
{
	return next;
}

// sets the next task to be the address of the parameter
void Task::setNextTask(Task& t) 
{
	next = &t;
}

// sets the paramter to the last customer order in the queue and removes it
// from the queue
// returns true on success
//
// NOTE: logic in linemanager is set up such that this function is only ever
// called on the LAST TASK on the assembly line which was already previously
// confirmed to be complete in the moveTask() function
bool Task::getCompleted(CustomerOrder& c)
{

	bool success {false};

	CustomerOrder& tmp = orders.back();
	// since this function is only ever called on the last task and after
	// calling runProcess on each task, logically the entire order must be
	// ready (getOrderFillState() will return true). Thus, there is 
	// actually no need to query the orders fill state here.

	if(!orders.empty()) { // technically my logic doesn't require the if!
		c = std::move(tmp);
		orders.pop_back();
		success = true;
	}
	
	return success;

}

// inserts the name of the current task as well as the next task
// into the reference to an output stream object in human-readable
// format
void Task::validate(std::ostream& os) const
{
	os << getName() << " --> " 
		<< (next ? next->getName() : "END OF LINE") << std::endl;
}

// moves the paramter onto the front of the customer order queue
Task& Task::operator+=(CustomerOrder&& c) 
{
	orders.push_front(std::move(c));
	return *this;
}
