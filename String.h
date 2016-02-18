//Andrew Niklas
//Exercise 6
//Completed 2/15/2016


#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>

class StringTester;

class String
{
    friend class StringTester;
	friend std::istream& operator>>(std::istream& is, const String& s);

private:
    // declare private members here
	char* data;
	int size;
	int allocated;
public:
    // declare public members here
	String();
	String(char c);
	String(const char* s);
	String(const String& other);
	~String();
	
	String& operator=(const String& right);
	
	int length() const;
	char charAt(int n) const;
	int indexOf(char c) const;
	char& operator[](int n);
	const char& operator[](int n) const;
	
	String operator+(const String& right) const;
	String operator+(char c) const;
	
	bool operator==(const String& right) const;
	bool operator<(const String& right) const;
	bool operator!=(const String& right) const;
	bool operator>(const String& right) const;
	bool operator<=(const String& right) const;
	bool operator>=(const String& right) const;
	
	String substring(int start, int end) const;
	std::string str() const;
};

std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);

#endif
