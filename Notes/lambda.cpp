#include <iostream>


int get10() {
	return 10;
}

int main() {
	int newnum = 6;
	int num = 5;
	auto add5Val = [=]()mutable {return (num += 5); };
	auto add5Ref = [&]()mutable {return (num += 5); };
	auto addUnknownVar = [&](int inNum)mutable {return (num += inNum); };
	auto addVarWithRef = [=, &newnum]()mutable {return (num += (++newnum)); };


	std::cout <<"Add 5 returns: [=]()mutable {return (num += 5); }  :"<< add5Val()<< std::endl;
	std::cout << "nums value: " << num <<", This is because we captured by value [=]" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Add 5 returns: [&]()mutable {return (num += 5); }   :" << add5Ref() << std::endl;
	std::cout << "nums value: " << num << ", This is because we captured by value [&]" << std::endl;
		

	std::cout<<"-------------------------------------------------------" << std::endl;
	std::cout << "This function allows external variables to be passed in: " 
		<< addUnknownVar(get10()) << "   [&](int inNum)mutable {return (num += inNum); }"<< std::endl ;

	std::cout << "nums value: " << num << ", This is because we passed in results from get10()" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Finally we're going to use the capture list to restrict some of the variables passed:" <<
		std::endl<<"[=, &newnum]()mutable {return (num += (++newnum)); }"<<std::endl<< "nums current value: " << num << ", newNum's current value: " << newnum <<std::endl;
	addVarWithRef();
	std::cout << "nums value: " << num << ", newNum's value: " << newnum << std::endl;
	std::cout << "This is because our capture list looks like this: [=, &newnum] = says to use copies. "<<std::endl <<
		"&newnum overides it saying it can use a reference" << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "Please mess around and look at the code! This is the best way to learn it. You must apply what you learn." << std::endl;
	




	std::cin.get();
	return 0;
}
