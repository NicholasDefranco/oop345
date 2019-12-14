// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, October 1st, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

// Note: extra parts were added for practicing purposes

// Header safeguard
#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

// Include files
#include <iostream>
#include <iomanip>

namespace sdds
{
	template<typename L, typename V>
	class LVPair 
	{

		// Label-value pair data
		L label {};
		V value {};

		public:
		
		// Default constructor
		LVPair() = default;
	
		// Custom 2-arg constructor, stores data into data members
		LVPair(const L& aa, const V& bb) : label{aa}, value{bb} {}
		
		// Rule of 3 (no move operators since all members are static)
		// (extra, not required for the assignment)
		// Copy constructor
		LVPair(const LVPair& l)
		{
			*this = l;
		}

		// copy assignment operator
		LVPair& operator=(const LVPair& l)
		{
			if(this != &l) {
				this->label = l.label;
				this->value = l.value;
			}
			return *this;
		}

		// Destructor
		virtual ~LVPair() = default;

		// Returns the label of the pair
		inline const L& key() const 
		{
			return label;
		}

		// Returns the value of the pair
		inline const V& val() const 
		{
			return value;
		}

		// Inserts data (label-value pair) into output stream
		virtual std::ostream& display(std::ostream& os) const
		{
			return os << label << " : " << value << std::endl;
		}

	};
	
	// Inserts object into output stream
	template<typename L, typename V>
	inline std::ostream& operator<<
		(std::ostream& os, const LVPair<L, V>& pair) 
	{
		return pair.display(os);		
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		
		// For static variables...
		// Every class with differing template parameter lists
		// will have their own init variable
		
		// Holds the initial value of the summation
		static V init;

		// Holds the minimum width for the labels passed
		static size_t min;

		public:
		// Returns the value of init
		inline static const V& getInitialValue() 
		{
			return init;
		}

		// Using constructors that have not been shawdowed
		// (extra)
		using LVPair<L, V>::LVPair;

		// 2-arg constructor
		// Updates the minimum field with if neccessary
		SummableLVPair(const L& lbl, const V& val) 
						: LVPair<L, V>(lbl, val)
		{
			if(lbl.size() > min) 
				min = lbl.size();	
		}

		// Copy assignment operator
		// (extra)
		SummableLVPair& operator=(const SummableLVPair& s)
		{
			LVPair<L, V>::operator=(s);	
			return *this;
		}

		// Destructor
		// (extra)
		~SummableLVPair() override = default;

		// Returns the sum of value stored in the current object and
		// the value passed
		V sum(const L& lbl, const V& val) const
		{
			return LVPair<L, V>::key() == lbl ? 
				LVPair<L, V>::val() + val : val;
		}

		// Inserts the label value pair in a formatted fashion
		std::ostream& display(std::ostream& os) const override
		{
			os << std::left << std::setw(min);
			return LVPair<L, V>::display(os) << std::right;
		}

	};

	// Required definition for static variablew (min) outside the class to
	// initialize the variable
	template <typename L, typename V>
	size_t SummableLVPair<L, V>::min = 0u;

	// Specializations
	// initial values for the start of a summation
	template<>
	std::string SummableLVPair<std::string, std::string>::init = "";

	template<>
	int SummableLVPair<std::string, int>::init = 0;

	// Specialization for std::string types, concatenates the current 
	// object's value with the value recieved as a parameter
	template<>
	std::string SummableLVPair<std::string, std::string>::sum
			(const std::string& lbl, const std::string& val) const
	{
		std::string tmp = {};
		if(key() == lbl) {
			if(!val.empty()) {
				tmp = val + ", " + 
				LVPair<std::string, std::string>::val();
			} else {
				tmp = LVPair<std::string, std::string>::val();
			}
		} else {
			tmp = val;
		}
		return tmp;
	}

}


#endif // SDDS_LVPAIR_H
