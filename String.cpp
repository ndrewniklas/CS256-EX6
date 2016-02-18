//Andrew Niklas
//Homework 4
//Completed 2/15/2016


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
	String s = String(temp);
	delete [] temp;
	return s;
}

String String::operator+(char c) const{
	char* temp = new char[size + 2];
	for(int i = 0; i < size; ++i){
		temp[i] = data[i];
	}
	temp[size] = c;
	temp[size + 1] = '\0';
	
	String s = String(temp);
	delete [] temp;
	return s;
}

bool String::operator==(const String& right) const{
	if(size != right.size){
		return false;
	}else{
		for(int i = 0; i < size; ++i){
			if(data[i] != right.data[i]){
				return false;
			}
		}
		return true;
	}
}

bool String::operator<(const String& right) const{
	for(int i = 0; i < size; ++i){
		if(data[i] < right.data[i]){
			break;
		}else{
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& right) const{
	return !(*this == right);
}

bool String::operator>(const String& right) const{
	if(!(*this == right)){
		return !(*this < right);
	}
	return false;
}

bool String::operator<=(const String& right) const{
	if((*this == right) || (*this < right)){
		return true;
	}else{
		return false;
	}
}

bool String::operator>=(const String& right) const{
	if((*this == right) || (*this > right)){
		return true;
	}else{
		return false;
	}
}

String String::substring(int start, int end) const{
	if(start < 0 || start > size){
		return String();
	}else if(end <= start){
		return String();
	}else if(end > size){
		end = size;
	}
	char* temp = new char[end - start];
	int j = 0;
	for(int i = start; i < end; ++i, ++j){
		temp[j] = data[i];
	}
	temp[j] = '\0';
	
	String s = String(temp);
	delete [] temp;
	return s;
}

std::string String::str() const{
    std::string str;
    for (int i = 0; i < size; i++)
    {
        str.push_back(data[i]);
    }
    return str;
}

std::ostream& operator<<(std::ostream& os, const String& s){
	os << s.str();
	return os;
}

std::istream& operator>>(std::istream& is, String& s){
	std::string str;
	is >> str;
	s = String(str.c_str());
	return is;
}
























