#pragma once
#include<iostream>
#include<exception>
#include<stdexcept>
#include<stack>
using namespace std;

class DivisionByZeroException : public exception
{
	DivisionByZeroException(const char* message) : exception(message) {}

	/*void Massage()
	{
		cout << what() << endl;
	}*/
	
};

class NegativeSideLengthOfTheFigureException : public exception
{
	NegativeSideLengthOfTheFigureException(const char* message) : exception(message) {}
};

class ArraySizeException : public length_error
{
	ArraySizeException(const string& massage) : length_error(massage) {}
};

class TheIndexIsNotÑorrect : public out_of_range
{
	TheIndexIsNotÑorrect(const string& massage) : out_of_range(massage) { }
};

class StackOverflow : public overflow_error
{
	StackOverflow(const string& massage) : overflow_error(massage) {}
};


