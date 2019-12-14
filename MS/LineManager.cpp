// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, December 1st, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <cassert>
#include <iterator>
#include <algorithm>
#include <functional>
#include <fstream>
#include "Utilities.h"
#include "LineManager.h"

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
LineManager::LineManager(const std::string& file, std::vector<Task *>& l,
		std::vector<CustomerOrder>& p)
{

	size_t i {0ul};
	bool more {true};
	Utilities util {};

	Task *curr {nullptr};
	Task *next {nullptr};

	std::string line {};
	std::string tmp {};

	std::fstream f(file, std::ios::in);	
	if(!f)
		throw std::string("Unable to open [") + file + "] file.";

	while(getline(f, line)) {
		tmp = util.extractToken(line, i, more);

		if(more) {

			curr = *std::find_if(l.cbegin(), l.cend(), 
							[&tmp](const Task *t) {
				return t->getName() == tmp;
			});
					
			tmp = util.extractToken(line, i, more);

			next = *std::find_if(l.cbegin(), l.cend(), 
						[&tmp](const Task *t) {
				return t->getName() == tmp;
			});

			if(next)
				curr->setNextTask(*next);

		}
		i = 0ul;
		more = true;
	}

	total_orders = p.size();

	// since we know the complete deque will eventually be the same size
	// as the process deque (AKA ToBeFilled deque), I am preallocating 
	// memory to the deque for efficiency
	complete.resize(total_orders);

	std::copy(make_move_iterator(p.begin()), make_move_iterator(p.end()), 
						front_inserter(process));

	this->line = l;

	// finds the first task in the assembly line
	first = *find_if(this->line.cbegin(), this->line.cend(), 
						[this](const Task *t) {
		const Task *tmp = t;
		size_t j {0ul};
		while(tmp) {
		         tmp = tmp->getNextTask();
			 j++;
		}

		return j == this->line.size();
	});

}

// runs one process cycle
// moves the last order on the process queue onto the start of the 
// assembly line(if any)
//
// runs a cycle for each Task on the assembly line
//
// moves the last order to the next task on the line(if task completed)
//
// returns true if all orders have been filled
bool LineManager::run(std::ostream& os)
{

	if(!process.empty()) {
		*(first) += std::move(process.back());
		process.pop_back();
	}

	for_each(line.begin(), line.end(), [&os](Task *t) {
		t->runProcess(os);
	});

	for_each(line.begin(), line.end(), [this](Task *t) {
		// moveTask() returns true if t is the last task and 
		// the last item on it's orders deque has been filled
		if(t->moveTask() && t->getCompleted(complete[complete_cnt]))
			complete_cnt++;
	});

	return complete_cnt == total_orders;
}

// inserts all CustomerOrder data stored in each completed order
// into the reference to an ostream object
void LineManager::displayCompleted(std::ostream& os) const 
{
	for_each(complete.cbegin(), complete.cend(), 
					[&os](const CustomerOrder& c) {
		c.display(os);
	});
	
}

// validates each task on the line
void LineManager::validateTasks() const
{
	for_each(line.cbegin(), line.cend(), [](const Task *t) {
		t->validate(std::cout);
	});
}
