// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 5th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"

void loadData(const char* filename, sdds::Autoshop& as)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
// TODO: This code can throw errors to signal that something went wrong while
//       extracting data. Write code to catch and handle the following errors:
//  -the type of vehicle is not recognized: the first non-empty character
//        on the line is not 'c', 'C', 'r', or 'R'. In this case print
//        "Unrecognized record type: [TAG]<endl>"
//  -one of the fields in the record contains invalid data. In this case print
//        "Invalid record!<endl>"
		try {
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		} catch(const std::string& msg) {
			// since the action taken by the client is the same
			// regardless of the exception thrown during
			// construction (which is ignoring the rest of the 
			// line), I have made all throw expressions to be 
			// of the same type.
			file.ignore(std::numeric_limits
					<std::streamsize>::max(), '\n');
			std::cerr << msg << std::endl;	
		}
	}
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(std::cout);
	std::cout << "\n";
	loadData(argv[2], as);
	as.display(std::cout);

	std::cout << std::endl;
	std::list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as 
		//	 parameter `const sdds::Vehicle*` and returns true 
		//	 if the vehicle has a top speed >300km/h
		auto fastVehicles = [](const sdds::Vehicle *v) -> bool {
			return v->topSpeed() > 300.0;
		};

		as.select(fastVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "|       Fast Vehicles          |\n";
		std::cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	vehicles.clear();
	std::cout << std::endl;
	{
		// TODO: Create a lambda expression that receives as 
		//	 parameter `const sdds::Vehicle*` and returns true 
		//	 if the vehicle is broken and needs repairs.
		auto brokenVehicles = [](const sdds::Vehicle *v) {
			return v->condition() == "broken";
		};

		as.select(brokenVehicles, vehicles);
		std::cout << "--------------------------------\n";
		std::cout << "| Vehicles in need of repair   |\n";
		std::cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(std::cout);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------\n";
	}

	return 0;
}
