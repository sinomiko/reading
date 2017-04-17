#include <iostream>
using namespace std;

class Test
{
public:
	int num_;
};

//num_ = 20;		Error,num_的作用域在类内部
int num_ = 20;		// num_的作用域是文件作用域，与类中的num_是不同的作用域

int add(int a, int b);	// a, b两个标识符的作用域为函数原型作用域

int main(void)
{
	int num_ = 30;		// num_为块作域
	{
		int num_ = 100;	// num_为块作域
	}

	cout<<num_<<endl;
	cout<<::num_<<endl;
	return 0;
}

int add(int a, int b)	// 形参a与b也算是块作用域
{
	return a + b;
}

int test()
{
LABEL1:
	cout<<"label1"<<endl;
	goto LABEL3;
LABEL2:
	cout<<"label2"<<endl;
	goto LABEL1;
LABEL3:
	cout<<"label3"<<endl;
	goto LABEL2;
}