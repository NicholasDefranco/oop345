#pragma once
#include <string>

class School 
{
	std::string name;
	int students;
public:
	std::string getName();
	void setName(std::string);
	int getStudents();
	void setStudents(int);
	void display();
	School();
	~School();
	School(int, std::string);
	School& operator=(School&);
	School(School&);
};

