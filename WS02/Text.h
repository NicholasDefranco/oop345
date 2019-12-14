// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, Spetember 24th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguard
#ifndef SDDS_TEXT_H 
#define SDDS_TEXT_H

// include files
#include <string>

namespace sdds 
{

	class Text {

		// size of dynamic std::string array
		size_t no {0u};

		// dynamic std::string array
		std::string *strs = nullptr;

		public:
		// default constructor
		Text() = default;

		// custom one-arg constructor
		Text(const char *);

		// copy constructor
		Text(const Text&);

		// move constructor
		Text(Text&&);

		// copy assignment operator
		Text& operator=(const Text&);

		// move-assignment operator
		Text& operator=(Text&&);

		// destructor
		~Text();

		// returns size of the std::string array
		size_t size() const;

	};

}

#endif // SDDS_TEXT_H
