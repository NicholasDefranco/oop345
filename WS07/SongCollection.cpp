// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 12th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// include files
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <fstream>
#include <iterator>
#include "SongCollection.h"

// used this function from the main file as it is useful
// when creating the footer
extern void printbar(std::ostream& out = std::cout);

namespace sdds 
{

	// member functions for the Song struct were not required for this
	// workshop. This was an extra part I added simply for
	// experimentation
	//
	// overloaded = operator simply copies the contents 
	// of the reference to a string object to the album member
	//
	// this function was required to be able to use the replace_if 
	// function in SongCollection::cleanAlbum()
	std::string Song::operator=(const std::string& al) 
	{
		return album = al;
	}

	// receives the name of a file
	// reads from the recieved input stream in,
	// and stores information read into the data members
	SongCollection::SongCollection(const std::string& file) 
	{
		// since I am reading the file in binary access mode
		// I require a temporary string to hold the numeric data
		// to be converted to a number
		std::string tmpstr {};

		std::fstream f(file, std::ios::in | std::ios::binary);

		if(!f)
			throw "Bad File Name!";


		// all numeric field have exactly MAX_NUM_SIZE field size in
		// the file
		tmpstr.resize(MAX_NUM_SIZE);


		// NOTE: &stringobj[0] returns a modifiable address to the 
		// first element of the underying character array that a string
		// class manages

		// NOTE: This function was not marked with "DO NOT USE MANUAL
		// LOOPS" in the instructions. Therefore, I used a while loop
		// that will iterate for each record found in the file
		while(!f.eof()) {

			Song tmp {};

			// allocate memory to strings...
			tmp.artist.resize(MAX_STR_SIZE);
			tmp.title.resize(MAX_STR_SIZE);
			tmp.album.resize(MAX_STR_SIZE);

			f.read(&tmp.title[0], MAX_STR_SIZE);
			trim(tmp.title);

			f.read(&tmp.artist[0], MAX_STR_SIZE);
			trim(tmp.artist);

			f.read(&tmp.album[0], MAX_STR_SIZE);
			trim(tmp.album);


			// for numeric fields, fields can either be a number
			// or a field simply consisting of spaces
			f.read(&tmpstr[0], MAX_NUM_SIZE);

			// if something other than a space character was read
			// implying that a number was read
			if(tmpstr.find_first_not_of(' ') != std::string::npos) 
				tmp.year = stoul(tmpstr);

			f.read(&tmpstr[0], MAX_NUM_SIZE);
			if(tmpstr.find_first_not_of(' ') != std::string::npos) 
				tmp.length = stoul(tmpstr);

			f.read(&tmpstr[0], MAX_NUM_SIZE);
			if(tmpstr.find_first_not_of(' ') != std::string::npos) 
				tmp.price = stod(tmpstr);

			// ignore any characters left on the line
			f.ignore(std::numeric_limits
					<std::streamsize>::max(), '\n');

			songs.push_back(std::move(tmp));
		}

	}

	// displays each song the in the collection in human-readable format
	// as well as displaying a footer that displays the total length
	// of all the songs in the collection
	void SongCollection::display(std::ostream& os) const
	{
		unsigned long total {0ul};

		// originally had a for_each loop before I learned about the
		// ostream iterator and before I created my overloaded binary +
		// operator
		std::copy(songs.cbegin(), songs.cend(), 
				std::ostream_iterator<const Song&>(os, "\n"));

		// Note: accumulate calls my helper overloaded binary +
		// operator
		total = std::accumulate(songs.cbegin(), songs.cend(), 0ul);

		printbar(os);
		
		os << "| " << std::setfill(' ') << std::setw(FOOTER_WIDTH) 
			<< "Total Listening Time:" << std::setw(NUM_WIDTH) 
			<< (total / SEC_PER_MIN / MIN_PER_HOUR) << ':' 
			<< std::setw(NUM_WIDTH) 
			<< (total / SEC_PER_MIN % MIN_PER_HOUR) << ':' 
			<< std::setw(NUM_WIDTH) << (total % SEC_PER_MIN)
			<< std::right << " |" << std::endl;
	}

	// recieves the name of a field in a Song object
	// and sorts the collection in ascending order based on
	// that field
	void SongCollection::sort(const std::string& field) 
	{

		if(field == "title") {
			std::sort(songs.begin(), songs.end(),
					[](const Song& a, const Song& b) {
				return a.title < b.title;
			});
		} else if(field == "album") {
			std::sort(songs.begin(), songs.end(),
					[](const Song& a, const Song& b) {
				return a.album < b.album;
			});
		} else if(field == "length") {
			std::sort(songs.begin(), songs.end(),
					[](const Song& a, const Song& b) {
				return a.length < b.length;
			});
		} else {
			throw std::invalid_argument("field to sort by must"
					" be: title, album, or length");
		}
		
	}

	// removes the string "[None]" from the album field
	// and replaces it with an empty string
	//
	// (originally used a for_each() algorithm before my operator=
	// overload)
	void SongCollection::cleanAlbum() 
	{
		std::replace_if(songs.begin(), songs.end(), [](const Song& s) {
			return s.album == "[None]";
		}, "");
	}

	// recieves the name of an artist
	// returns true if the collection contains a 
	// song created by that artist
	bool SongCollection::inCollection(const std::string& name) const 
	{
		return std::any_of(songs.cbegin(), songs.cend(), 
					[&name](const Song& s) {
			return s.artist == name;
		});
	}

	// recieves the name of an artist
	// returns a list of list made by that artist that are 
	// present in the collection
	std::list<Song> SongCollection::getSongsForArtist
					(const std::string& name) const
	{
		std::list<Song> l {};
		std::copy_if(songs.cbegin(), songs.cend(), back_inserter(l),
						[&name](const Song& s) {
			return name == s.artist;
		});
		return l;
	}

	// displays the data stored in Song object s in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Song& s)
	{
		os << "| " << std::left << std::setw(TITLE_WIDTH) 
				<< s.title << " | " << std::setw(ARTIST_WIDTH) 
				<< s.artist << " | " << std::setw(ALBUM_WIDTH) 
				<< s.album << " | " << std::right 
				<< std::setw(YEAR_WIDTH);

		// if field was not empty in the file...
		if(s.year != 0ul) 
			os << s.year;
		else  
			os << "";

		os << " | " << std::setfill('0') 
				<< (s.length / SEC_PER_MIN % MIN_PER_HOUR) 
				<< ':' << std::setw(NUM_WIDTH)
				<< (s.length % SEC_PER_MIN) << " | " 
				<< std::setfill(' ') << std::fixed
				<< std::setprecision(PRICE_PREC)
				<< s.price << " |" 
				<< std::setprecision(DEFAULT_PREC);

		// good practice to unset all format manipulators in the same
		// function
		os.unsetf(std::ios::fixed);

		return os;
	}

	// helper function
	// overloaded binary addition operator
	// required function to allow me to use the accumlute algorithm
	// to sum the lengths of the songs
	//
	// just like the overloaded assignment operator declared as a member in
	// the Song struct, this was completely optional and was just used
	// simply for experimentation
	unsigned long operator+(unsigned long num, const Song& s)
	{
		return num + s.length;
	}

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str)
	{
		size_t i {str.find_first_not_of(' ')};
		str = str.substr(i, str.find_last_not_of(' ') - i + 1);
	}

}
