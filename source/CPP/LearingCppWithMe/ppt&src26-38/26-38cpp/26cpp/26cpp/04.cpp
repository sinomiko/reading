#include <string>
#include <iostream>
using namespace std;

void fun(char *str)
{
	cout<<str<<endl;
}

int main(void)
{
	string s1 = "abc";

	s1[1] = 'B';

	cout<<s1<<endl;

	const string s2 = "xyz";
	//s2[1] = 'Y';		Error s2[1] ·µ»ØµÄÊÇ const char&

	string s3 = "111" + s1 + "222" ;
	cout<<s3<<endl;

	//s3.c_str()
	fun(const_cast<char*>(s3.c_str()));

	return 0;
}