#ifndef _MAX_H_
#define _MAX_H_

#include <iostream>
using namespace std;

template <typename T>
const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}

// 函数模板重载
template <typename T>
const T& max(const T& a, const T& b, const T& c)
{
	return ::max(a, b) < c ? c : ::max(a, b);
}

// 非模板函数重载
const int& max(const int& a, const int& b)
{
	cout<<"non template function"<<endl;
	return a < b ? b : a;
}

// 函数模板特化
template <>
const char* const& max(const char* const&a, const char* const& b)
{
	cout<<"BBBBBBBBBB"<<endl;
	return strcmp(a, b) < 0 ? b : a;
}

// 非模板函数重载
const char* const& max(const char* const&a, const char* const& b)
{
	cout<<"AAAAAAAAAAAAA"<<endl;
	return strcmp(a, b) < 0 ? b : a;
}

#endif // _MAX_H_

