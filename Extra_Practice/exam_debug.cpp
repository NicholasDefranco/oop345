#include <iostream>
using namespace std;

struct A {

	const int x; // forbidden to change

public:

	A(const int c) : x(c) // constant data members must be initilized here
	{
		// x = c;
	}

	void operator()()
	{
		// cout << x << '/n';
		cout << x << '\n'; // replace forward slash with backslash
	}

};

void foo(void *c) // forbidden to change
{
	//cout << *c << ':';
	// cannot dereference a void pointer as it is an incomplete type (it is
	// a generic pointer type, compiler wouldn't know how to interpret 
	// the data stored at the address)
	//
	// a type cast is required to access the region of memory it points to
	// so the code should be:
	cout << *(static_cast<int *>(c)) << ':';
	// C-style casts would work just as good but our profs are cpp
	// programmers and they most likely want us to use the type-safe 
	// facilities of the language. Thus, I have used the static_cast<T>(v)
	// operator
	
}

int main(int argc, char *argv[])
{
	int c{ 5 }; // cannot change

	foo(&c); // cannot change

	A a(c); // cannot change

	//(c++)++;
	// the post-fix increment expression requires a modifiable l-value 
	// as its operand and expression itself results in a prvalue
	// Thus, using the result of a post-fix expression as an operand to
	// another post-fix expression is illegal
	//
	// The programmer obviously wanted to simply add two to the variable c
	// which we can do in many ways
	// here's one way:
	
	(++c)++;

	//if(argv[1][0] == 'x' && argc > 1)
	/*
	 * We should check if the argv[1] actually exists before we query it
	 *
	 * So the code should be:
	 */
	if(argc > 1 && argv[1][0] == 'x')
		a();

	return 0;
}
