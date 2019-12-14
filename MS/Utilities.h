// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Sunday, November 24th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguards
#ifndef UTILITIES_H
#define UTILITIES_H

// include files
#include <string>

class Utilities {
	
	size_t width {1ul};

	// since all instances of the class share the same width the member 
	// storing the width must be a class variable(static variable)
	static char delim;

	public:
	// default constructor
	Utilities() = default;

	// sets the field width to the value of the parameter
	void setFieldWidth(size_t w);

	// returns the field width
	size_t getFieldWidth() const noexcept;

	// recieves an unmodifiable reference to a string containing the 
	// record, the index of the next token, and a boolean indicating
	// whether or not the record has been completly extracted
	// 
	// this function extracts a token from the record and returns a
	// unmodifiable copy of it
	const std::string extractToken(const std::string& str, 
				size_t& next, bool& more);

	// sets the delimiter to the parameter
	static void setDelimiter(const char c);

	// returns a unmodifiable copy of the current delimiting character
	const char getDelimiter() const noexcept;

};


#endif // UTILITIES_H
