#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>

class StringTester;

class String
{
    friend class StringTester;

private:
    // declare private members here
	char* data;
	int size;
public:
    // declare public members here
	String();
	String(char c);
	String(const char* s);
	String(const String& other);
	~String();
	
};

#endif