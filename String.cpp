#include "String.h"

// this header has some useful functions
// for working with C-strings
#include <cstring>

// Put your function implementations here
String::String()
	:data(new char[10]), size(0), allocated(10)
{
}

String::String(char c)
	:data(new char[10]), size(1), allocated(10)
{
	data[0] = c;	
}

String::String(const char* s)
	:data(new char[strlen(s)]), size(strlen(s)), allocated(strlen(s))
{
	for(int i = 0; i < size; ++i){
		data[i] = s[i];
	}
}

String::String(const String& other)
	:data(new char[other.size]), size(other.size), allocated(other.size)
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
	allocated = 0;
}

String& String::operator=(const String& right){
	if(this == &right){
		return *this;
	}
	
	if(allocated < right.size){
		delete [] data;
		data = new char[right.size];
		allocated = right.size;
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

String String::operator+(const String& right) const{
	int newAlloc = allocated;
	if(allocated < (size + right.size)){
		if(size >= right.size){
			newAlloc = size * 2 + 1;
		}else{
			newAlloc = right.size * 2 + 1;
		}
	}
	char* temp = new char[newAlloc];
	int i = 0;
	for(; i < size; ++i){
		temp[i] = data[i];
	}
	for(int j = 0; j < right.size; ++j, ++i){
		temp[i] = right.data[j];
	}
	return String(temp);
}

String String::operator+(char c) const{
	int newAlloc = allocated;
	if(allocated < size + 1){
		newAlloc = size * 2 + 1;
	}
	char* temp = new char[newAlloc];
	int j = 0;
	for(int i = 0; i < size; ++i, ++j){
		temp[i] = data[i];
	}
	++j;
	temp[j] = c;
	return String(temp);
}

























