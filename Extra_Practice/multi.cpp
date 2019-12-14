#include <iostream>
#include <string>


using namespace std;
//Base Class **DON'T TOUCH**
class Person {
	string name;

public:
	Person(string x) : name{ x } {
		cout << "Person " << x << " Says Hi" << endl;
	}
	string sayMyName() {
		return name;
	}
};



//Q1) Class MOM inherits from Person. **Fix the class and the constructor**
class MOM : virtual public Person {
	string hair;
public:

	//2 arg constructor with 2 strings, **FIX ME**
	MOM(string _hair, string _name) :Person(_name+"MOM") {
		cout << "Created MOM" << endl;
		hair = _hair;
	}

	string getHair() {
		return hair;
	}

};


//Class DAD inherits from Person **Fix the class and the constructor**
class DAD : virtual public Person {
	string eyes;
public:

	//2 arg constructor with 2 strings **FIX ME**
	DAD(string _eyes, string _name) :Person(_name+"DAD") {
		cout << "Created DAD" << endl;
		eyes = _eyes;
	}

	string getEyes() {
		return eyes;
	}

};


//class kid inherits from both MOM and DAD
class KID : public MOM, public DAD {
	
public:

	//create 2 arg constructor with 2 strings, a name and hair. get it working with inheritence
	//
	KID(string _eyes, string _hair, string _name) : Person(_name), MOM(_hair, _name), DAD(_eyes, _name) {
		cout << "Created KID" << endl;
	}

};




int main() {
	KID Nate("Blue", "Black", "Nate");

	
	//**Do the correct argument calls**
	cout << "Hello my name is: " << Nate.sayMyName() << ". I have " << Nate.getEyes()
		<< " eyes, and " << Nate.getHair() << " hair. It's nice to meet you." << endl;

	/*Expected Output:
	Person Nate Says Hi
	Created MOM
	Created DAD
	Created KID
	Hello my name is: Nate. I have green eyes and red hair. It's nice to meet you. 
	*/

	cin.get();
	return 0;
}
