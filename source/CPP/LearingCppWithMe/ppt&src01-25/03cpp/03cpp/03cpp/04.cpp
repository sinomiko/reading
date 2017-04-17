#include <iostream>
using namespace std;

int fun(int a, int b=5)
{
	return a + b;
}

int fun(int a, int b, int c);


int main(void)
{
	cout<<fun(3)<<endl;
	cout<<fun(3, 4)<<endl;
	cout<<fun(3,4,5)<<endl;
	return 0;
}

int fun(int a, int b, int c)
{
	return a + b + c;
}