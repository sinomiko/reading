#include <iostream>
#include <string>
using namespace std;

#include "max.h"

class Test
{
public:
	
	friend bool operator<(const Test& t1, const Test& t2)
	{
		return true;
	}
};

int main(void)
{
	cout<<::max(5.5, 6.6)<<endl;		// 自动推导 max(const int&, const int&)
	cout<<::max('a', 'c')<<endl;		// 自动推导 max(const int&, const int&)

	Test t1;
	Test t2;
	::max(t1, t2);

	const char* str1 = "aaa";
	const char* str2 = "zzz";
	cout<<::max(str1, str2)<<endl;

	cout<<::max<>(str1, str2)<<endl;

	cout<<::max(1, 5, 3)<<endl;

	cout<<::max('a', 100)<<endl;

	cout<<::max(97, 100)<<endl;			// max(const int&, const int&);

	cout<<::max<>(97, 100)<<endl;		// 自动推导 max(const int&, const int&)
	cout<<::max<int>(97, 100)<<endl;	// 显式指定模板函数max(const int&, const int&)
	cout<<::max<int>('a', 100)<<endl;


	return 0;
}