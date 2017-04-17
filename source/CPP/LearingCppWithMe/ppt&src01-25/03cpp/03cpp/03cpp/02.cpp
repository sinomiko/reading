#include <iostream>
using namespace std;

int main(void)
{
	int* p = new int(33);			//分配一个整数空间 4字节
	cout<<*p<<endl;

	int* p2 = new int[10];		//分配连续的10个整数空间 40字节

	delete p;
	delete[] p2;
	return 0;
}