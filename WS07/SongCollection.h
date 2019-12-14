// Name: Nicholas Defranco
// Seneca Student ID: 106732183
// Seneca email: ndefranco@myseneca.ca
// Date of completion: Tuesday, November 12th, 2019
//
// I confirm that the content of this file is created by me,
// 	with the exception of the parts provided to me by my professor.

// header safeguard
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

// include files
#include <iostream>
#include <vector>
#include <list>
#include <string>

namespace sdds
{
	// constants representing the size of the fields in the file
	const size_t MAX_STR_SIZE {25ul};
	const size_t MAX_NUM_SIZE {5ul};

	// constants used to format data when inserted into an output stream
	const int TITLE_WIDTH {20};
	const int ARTIST_WIDTH {15};
	const int ALBUM_WIDTH {20};
	const int YEAR_WIDTH {6};
	const int NUM_WIDTH {2};

	const int DEFAULT_PREC {6};
	const int PRICE_PREC {2};

	// constants representing the rates for time
	const unsigned long SEC_PER_MIN {60ul};
	const unsigned long MIN_PER_HOUR {60ul};

	const int FOOTER_WIDTH {76};

	// contains information about a song
	struct Song {
		std::string artist {};
		std::string title {};
		std::string album {};
		double price {0.0};
		unsigned long year {0ul};
		unsigned long length {0ul};

		// member functions for the Song struct were not required for this
		// workshop. This was an extra part I added simply for
		// experimentation
		//
		// overloaded = operator simply copies the contents 
		// of the reference to a string object to the album member
		//
		// this function was required to be able to use the replace_if 
		// function in SongCollection::cleanAlbum()
		std::string operator=(const std::string& al);
	};

	// class managing a collection of songs
	class SongCollection {

		std::vector<Song> songs;

		public:
		// receives the name of a file
		// reads from the recieved input stream in,
		// and stores information read into the data members
		SongCollection(const std::string& file);

		// displays each song the in the collection in human-readable
		// format as well as displaying a footer that displays the 
		// total length of all the songs in the collection
		void display(std::ostream& os) const;

		// recieves the name of a field in a Song object
		// and sorts the collection in ascending order based on
		// that field
		void sort(const std::string& field);

		// removes the string "[None]" from the album field
		// and replaces it with an empty string
		void cleanAlbum();

		// recieves the name of an artist
		// returns true if the collection contains a 
		// song created by that artist
		bool inCollection(const std::string& name) const;

		// recieves the name of an artist
		// returns a list of list made by that artist that are 
		// present in the collection
		std::list<Song> getSongsForArtist
					(const std::string& name) const;

	};

	// displays the data stored in Song object s in a human-readable format
	std::ostream& operator<<(std::ostream& os, const Song& s);


	// helper function
	// overloaded binary addition operator
	// required function to allow me to use the accumlute algorithm
	// to sum the lengths of the songs
	//
	// just like the overloaded assignment operator declared as a member in
	// the Song struct, this was completely optional and was just used
	// simply for experimentation
	unsigned long operator+(unsigned long num, const Song& s);

	// helper function
	// removes leading and trailing space characters
	// off a modifiable reference to a std::string
	void trim(std::string& str);

}

#endif // SDDS_SONGCOLLECTION_H
