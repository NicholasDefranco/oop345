#include <iostream>
#include <fstream>  //FIX ME!!!!!!!       add stream library
#include <string>

static const char* text = "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam,\n eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit,\n sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem.\n Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas\n nulla pariatur?";

int main() {
	//DON'T TOUCH---------------------------------------------------------
	//This code creates a file if it doesn't already exists 
	//and overwrites the content to a long 'Lorum Ipsum' text string 
	std::fstream f("myText.txt", std::ios::out | std::ios::trunc);
	f << text;
	f.close();
	//DON'T TOUCH----------------------------------------------------------


	//Q1 go to the beginning of the file ([FLAG] Open the stream for output), output/overwrite while keeping the old text:  
	//Add this text ==> "OOP345 is the best course ever and I'm sad that I'm going to pass, and not have to do it again :C"
	//Write your code here:

	f.open("myText.txt", std::ios::out);
	f.seekp(0, std::ios::beg);
	f << "OOP345 is the best course ever and I'm sad that I'm going to pass, and not have to do it again :C " << text;
	f.close();



	//Q2 Append your name and Student number to the end of the file. ([FLAG] Open the stream for output)
	//Write your code here

	f.open("myText.txt", std::ios::out | std::ios::app);
	f << " Nicholas: 106732183";
	f.close();



	//Q3 create a string variable and loop through the entire file and print the results. ([FLAG] Open the stream for input)
	std::string myString{""}; //Empty string to add file contents to
	//Write your code here

	//f.open("myText.txt", std::ios::in | std::ios::binary);
	//f.seekg(0, std::ios::end);
	//int nbytes = f.tellg();
	//f.seekg(0, std::ios::beg);
//
	//myString.resize(nbytes);
	//f.read(&myString[0], nbytes);
//
	//std::cout << myString << std::endl;

	f.open("myText.txt", std::ios::in);

	while(!f.eof()) {
		std::getline(f, myString);
		std::cout << myString << std::endl;
	}

	f.close();

	//Q4 open in binary([FLAG] Binary) and read the first 20 characters and input them into the provided char string;
	//Write your code here
	char str[21]{"TEST\0"}; //a 20 character NULL terminated string

	f.open("myText.txt", std::ios::in | std::ios::binary);

	f.read(str, 20);


	std::cout << str << std::endl;

	return 0; 
}
