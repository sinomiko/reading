#include <iostream>
using namespace std;
#include <stdio.h>

#pragma pack(2)
struct Test
{
	char a;
	double b;
	char c;
};
#pragma pack()


//第一个成员与结构体变量的偏移量为0
//其它成员要对齐到某个数字（对齐数）的整倍数的地址
//对齐数取编译器预设的一个对齐整数与该成员大小的较小值
//结构体总大小为最大对齐数的整数倍


int main(void)
{
	Test test;
	//&test = &test.a;
	char *p= (char*)&test;
	//cout<<p<<endl;
	printf("p=%p\n", p);
	p = &test.a;
	printf("p=%p\n", p);

	cout<<sizeof(Test)<<endl;
	return 0;
}