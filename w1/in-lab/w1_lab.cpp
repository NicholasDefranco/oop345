// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, Spetember 13th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include "process.h"
#include "String.h"

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char **argv)
{

	std::cout << "Command Line:\n";
	// TODO: print the command line here, in the format
	for(int i = 0; i < argc; i++) 
		std::cout << i + 1 << ": " << argv[i] << std::endl;	

	std::cout << std::endl;

	if (argc < 2) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		return 1;
	}

	std::cout << "------------------\n";
	std::cout << "Global variable:\n";
	std::cout << "------------------\n";
	std::cout << "Old Value: " << sdds::g_maxSize << '\n';
	sdds::g_maxSize = 4;
	std::cout << "New Value: " << sdds::g_maxSize << '\n';
	std::cout << "------------------\n\n";

	std::cout << "------------------\n";
	std::cout << "Processing:\n";
	std::cout << "------------------\n";
	for (int i = 1; i < argc; i++)
		sdds::process(argv[i]);
	std::cout << "------------------\n\n";

	return 0;
}
