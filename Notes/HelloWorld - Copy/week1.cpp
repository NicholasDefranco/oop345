#include <iostream>
#include "school.h"

int main() {
	School Seneca;
	/*Seneca.setName("George Brown");
	Seneca.setStudents(5);*/
	School GB;
	School Durham(GB = Seneca);
	School York(40000, "York Uni");
	Seneca.setName("Seneca");
	Seneca.setStudents(20000000);
	Seneca.display();
	GB.display();
	Durham.display();
	

	std::cin.get();
	return 0;
}