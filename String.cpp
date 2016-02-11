#include "String.h"

// this header has some useful functions
// for working with C-strings
#include <cstring>

// Put your function implementations here
String::String()
	:data(new char[10]), size(0)
{
}

String::String(char c)
	:data(new char[10]), size(1)
{
	data[0] = c;	
}

String::String(const char* s)
	:data(new char[strlen(s)]), size(strlen(s))
{
	for(int i = 0; i < size; ++i){
		data[i] = s[i];
	}
}

String::String(const String& other)
	:data(new char[other.size]), size(other.size)
{
	for(int i = 0; i < size; ++i){
		data[i] = other.data[i];
	}
}

String::~String(){
	delete [] data;
}