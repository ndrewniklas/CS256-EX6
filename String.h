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
	
};

#endif