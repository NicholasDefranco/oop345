// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, Spetember 24th, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <fstream>
#include "Text.h"

namespace sdds 
{

	// custom one-arg constructor
	Text::Text(const char *name) 
	{
		std::fstream f(name, std::ios::in);

		if(!f) 
			return;

		while(f) {
			if(f.get() == ' ') {
				no++;
			}
		}

		this->strs = new std::string[no];

		f.clear();
		f.seekp(std::ios::beg);

		for(unsigned i = 0; i < no; i++) 
			getline(f, this->strs[i], ' ');


	}

	// destructor
	Text::~Text() 
	{
		delete [] this->strs;
	}

	// copy constructor
	Text::Text(const Text& t)
	{
		*this = t;
	}

	// move constructor
	Text::Text(Text&& t) 
	{
		*this = std::move(t);
	}

	// copy assignment operator
	Text& Text::operator=(const Text& t)
	{
		if(this != &t) {
			this->no = t.no;
			delete [] this->strs;
			if(t.strs != nullptr) {
				this->strs = new std::string[t.no];
				for(unsigned i = 0; i < t.no; i++) {
					this->strs[i] = t.strs[i];
				}
			} else {
				this->strs = nullptr;
			}
		}
		return *this;
	}

	// move assignment operator
	Text& Text::operator=(Text&& t) 
	{
		if(this != &t) {
			delete [] this->strs;

			this->strs = t.strs;
			this->no = t.no;

			t.strs = nullptr;
			t.no = 0u;
		}
		return *this;
	}

	// returns size of the std::string array
	size_t Text::size() const 
	{
		return no;
	}

}
