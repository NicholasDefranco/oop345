// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <string>

namespace sdds 
{

	// size of statically allocated arrays
	const size_t MAX {5u};

	// functor
	class SpellChecker 
	{
		// statically allocated arrays to store the words read from
		// the word.txt text file
		std::string badwords[MAX];
		std::string goodwords[MAX];

		public:
		// one arg constructor
		// accepts a name of a file
		// reads the contents of the file and stores the data into
		// the data members
		// throws exception if file failed to open
		SpellChecker(const char *file);

		// accepts a modifiable std::string object
		// corrects misspelled words in the array passed
		void operator()(std::string& text) const;
	};
}

#endif // SDDS_SPELLCHECKER_H
