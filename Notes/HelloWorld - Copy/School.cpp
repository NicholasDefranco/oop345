#include "school.h"
#include <iostream>

std::string School::getName() {
	return name;
}

void School::setName(std::string nName) {
	this->name = nName;
}
int School::getStudents() {
	return students;
}
void School::setStudents(int nStudents) {
	this->students = nStudents;
}
void School::display() {
	std::cout << getName() << " has: " << getStudents() << " Students" << std::endl;
}





School::School() : name(""), students(0)
{ }

School::~School()
{

}

School::School(int num, std::string name) {/*
	students = num;
	this->name = name;*/
}

School& School::operator=(School& A) {
	if (this != &A){
		this->name = A.name;
		this->students = A.students;
	}
	return *this;
}

School::School(School& A) {
	*this = A;
}


