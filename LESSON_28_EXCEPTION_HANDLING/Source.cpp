/*EXCEPTION_HANDLING_1_TRY_AND_CATCH*/
/*#include <iostream> 
using namespace std; 

int main()
{
	cout << "Enter number of integers you wish to reserve: ";
	try
	{
		int input = 0;
		cin >> input; 

		//Request memory space and the return it
		int* numArray = new int[input];
		delete[] numArray;
	}
	catch (...)
	{
		cout << "Exception occurred. Go to end. Sorry!" << "\n"; 
	}
	return 0; 
}*/

/*EXCEPTION_HANDLING_2_CATCHING_BAD_ALLOCATION*/
/*
#include <iostream>
#include <exception> //include this to catch exception bad_alloc
using namespace std; 

int main()
{
	cout << "Enter number of integers you wish to reserve: ";
	try
	{
		int input = 0;
		cin >> input;

		//Request memory space and then return it
		int* numArray = new int[input];
		delete[] numArray;
	}
	catch (std::bad_alloc& exp)
	{
		cout << "Exception encountered: " << exp.what() << "\n"; 
		cout << "Got to end, sorry!" << "\n"; 
	}
	catch (...)
	{
		cout << "Exception encountered. Got to end, sorry!" << "\n"; 
	}
	return 0;
}*/

/*EXCEPTION_HANDLING_3_THROW*/
/*
#include <iostream> 
using namespace std; 

double Divide(double dividend, double divisor)
{
	if (divisor == 0)
		throw "Dividing by 0 is a crime";

	return (dividend / divisor);
}

int main()
{
	cout << "Enter dividend: "; 
	double dividend = 0; 
	cin >> dividend;
	cout << "Enter divisor: ";
	double divisor = 0;
	cin >> divisor; 

	try
	{
		cout << "Result is: " << Divide(dividend, divisor);
	}
	catch (const char* exp)
	{
		cout << "Exception: " << exp << "\n"; 
		cout << "Sorry, can't continue!" << "\n"; 
	}

	return 0;
}*/

/*EXCEPTION_HANDLING_4_DESTRUCTION_ORDER*/
/*#include <iostream>
using namespace std; 

struct StructA
{
	StructA() { cout << "StructA constructor" << "\n"; }
	~StructA() { cout << "StructA destructor" << "\n"; }
};

struct StructB
{
	StructB() { cout << "StructB constructor" << "\n"; }
	~StructB() { cout << "StructB destructor" << "\n"; }
};

void FuncB() //throws
{
	cout << "In Func B" << "\n"; 
	StructA objA; 
	StructB objB;
	cout << "About to throw up!" << "\n"; 
	throw "Throwing for the heck of it"; 
}

void FuncA()
{
	try {
		cout << "In Func A" << "\n"; 
		StructA objA;
		StructB objB; 
		FuncB();
		cout << "FuncA: returning to caller" << "\n"; 
	}
	catch (const char* exp)
	{
		cout << "FuncA: Caught exception: " << exp << "\n"; 
		cout << "Handled it, will not throw to caller" << "\n"; 
		//throw; //uncomment this line to throw to main()
	}
}

int main()
{
	cout << "main(): Started execution" << "\n"; 
	try
	{
		FuncA();
	}
	catch (const char* exp)
	{
		cout << "Exception : " << exp << "\n";
	}
	cout << "main(): exiting gracefully" << "\n"; 
	return 0;
}*/

/*EXCEPTION_HANDLING_5_CUSTOM_EXCEPTION*/
/*
#include <exception>
#include <iostream>
#include <string> 
using namespace std; 

class CustomException : public std::exception {
	string reason;
public:
	//constructor, needs reason 
	CustomException(const char* why) :reason(why) {}

	//redefining virtual function to return 'reason'
	virtual const char* what() const throw()
	{
		return reason.c_str();
	}
};

double Divide(double dividend, double divisor)
{
	if (divisor == 0)
		throw CustomException("CustomException: Dividing by 0 is a crime");

	return (dividend / divisor);
}

int main()
{
	cout << "Enter dividend: ";
	double dividend = 0;
	cin >> dividend; 
	cout << "Enter divisor: ";
	double divisor = 0;
	cin >> divisor;
	try
	{
		cout << "Result is: " << Divide(dividend, divisor);
	}
	catch (exception& exp)//catch CustomException, bad_alloc, etc 
	{
		cout << exp.what() << "\n"; 
		cout << "Sorry, can't continue!" << "\n"; 
	}

	return 0;
}*/

