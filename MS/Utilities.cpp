// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, November 24th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include  <iostream>
#include "Utilities.h"

// complementary definition of class variable
// I have chosen the default delimiter to be a comma
char Utilities::delim {','};

// sets the field width to the value of the parameter
//
// (extra) added a validation check, an attempt to reassign the width 
// to a negative integer will simply be ignored
void Utilities::setFieldWidth(size_t w) 
{
	if(w >= 0ul)
		width = w;	
}

// returns the field width
size_t Utilities::getFieldWidth() const noexcept
{
	return width;
}

// recieves an unmodifiable reference to a string containing the 
// record, the index of the next token, and a boolean indicating
// whether or not the record has been completly extracted
// 
// this function extracts a token from the record and returns a
// unmodifiable copy of it
const std::string Utilities::extractToken(const std::string& str, 
						size_t& next, bool& more)
{
	std::string tmp {};

	// safe guard check in case it is called an extra time...
	if(more) {
		size_t i = str.find(delim, next);

		if(i == std::string::npos)
			more = false;
		else if(i == next)
			throw "No token";

		tmp = str.substr(next, i - next);	

		if(tmp.size() > width) 
			setFieldWidth(tmp.size());

		next = i + 1ul;
	}

	return tmp;	
}

// sets the delimiter to the parameter
void Utilities::setDelimiter(const char c) 
{
	delim = c;
}

// returns a unmodifiable copy of the current delimiting character
const char Utilities::getDelimiter() const noexcept
{
	return delim;
}
