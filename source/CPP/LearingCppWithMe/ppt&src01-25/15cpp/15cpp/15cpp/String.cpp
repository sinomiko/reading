#include "String.h"
//#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;

String::String(char* str/* = */)
{
	str_ = AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

String::String(const String& other)
{
	str_ = AllocAndCpy(other.str_);
}

String& String::operator =(const String &other)
{
	if (this == &other)
		return *this;
	
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

char* String::AllocAndCpy(char* str)
{
	int len = strlen(str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display()
{
	cout<<str_<<endl;
}