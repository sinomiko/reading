#include <iostream>
using namespace std;


void fun(int a, int b)
{
	cout<<"int fun"<<endl;
}

void fun(double a, double b)
{
	cout<<"double fun"<<endl;
}

//extern "C"表示不进行名字改编
#ifdef __cpluscplus
extern "C"
{
#endif
void fun(int a)
{
	cout<<"xxxx"<<endl;
}
void fun2(double a)
{
	cout<<"yyyy"<<endl;
}
#ifdef __cpluscplus
}
#endif

int main(void)
{
	fun(3,4);
	fun(3.3, 4.4);
	fun(3);
	return 0;
}