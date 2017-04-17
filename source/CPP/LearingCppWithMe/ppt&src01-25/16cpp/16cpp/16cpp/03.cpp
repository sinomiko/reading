#include <iostream>
using namespace std;

class Test
{
public:
	Test(int y) : y_(y)
	{

	}
	~Test()
	{

	}

	void TestFun()
	{
		cout<<"x="<<x_<<endl;	//OK,非静态成员函数可以访问静态成员
		TestStaticFun();
	}
	static void TestStaticFun()
	{
		cout<<"TestStaticFun ..."<<endl;
		//TestFun();		Error,静态成员函数不能调用非静态成员函数
		//cout<<"y="<<y_<<endl;		Error,静态成员函数不能访问非静态成员
	}
	static int x_;		// 静态成员的引用性说明
	int y_;
};

int Test::x_ = 100;		// 静态成员的定义性说明

int main(void)
{
	Test t(10);
	cout<<Test::x_<<endl;
	t.TestFun();

	cout<<t.x_<<endl;		// 可以访问，但不推荐这么使用
}