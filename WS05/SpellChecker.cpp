// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Friday, October 18th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"

namespace sdds
{
	// one arg constructor
	// accepts a name of a file
	// reads the contents of the file and stores the data into
	// the data members
	// throws exception if file failed to open
	SpellChecker::SpellChecker(const char *file) 
	{
		std::fstream f(file, std::ios::in);
		if(!f){
			throw "Bad file name!";
		}

		for(size_t i {0u}; !f.eof() && i < MAX; i++) {
			f >> badwords[i];
			if(!f.eof()) {
				f >> goodwords[i];
			}
		}
	}

	// accepts a modifiable std::string object
	// corrects misspelled words in the array passed
	void SpellChecker::operator()(std::string& text) const
	{
		for(size_t i {0u}; i < MAX; i++) {
			size_t index {0u};
			while((index = text.find(badwords[i], index))
						!= std::string::npos) {
				text.replace(index, badwords[i].size(), 
						goodwords[i]);

				index += goodwords[i].size();
			}
		}
	}
}
