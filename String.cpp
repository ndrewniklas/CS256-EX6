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
	if(data != nullptr){
		delete [] data;
		data = nullptr;
	}
	size = 0;
}

String& String::operator=(const String& right){
	if(this == &right){
		return *this;
	}
	
	if(size < right.size){
		delete data;
		data = new char[right.size];
		size = right.size;
	}
	size = right.size;
	for(int i = 0; i < size; ++i){
		data[i] = right.data[i];
	}
	return *this;
}

int String::length() const{
	return size;
}

char String::charAt(int n) const{
	return data[n];
}

int String::indexOf(char c) const{
	for(int i = 0; i < size; ++i){
		if(data[i] == c){
			return i;
		}
	}
	return -1;
}

char& String::operator[](int n){
	//if modifing
	return data[n];	
}

const char& String::operator[](int n) const{
	//if reading
	return data[n];
}

























