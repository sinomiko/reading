#include <iostream>
#include <memory>
using namespace std;

class Noncopyable
{
protected:
	Noncopyable() {}
	~Noncopyable() {}
private:
	Noncopyable(const Noncopyable&);
	const Noncopyable& operator=(const Noncopyable&);
};


class Parent : private Noncopyable
{
public:
	Parent()
	{

	}
	Parent(const Parent& other) : Noncopyable(other)
	{

	}
};

class Child : public Parent
{
public:
	//Child(const Child& other)
	//{

	//}
};

int main(void)
{
	Parent p1;
	Parent p2(p1);		// 要调用Parent拷贝构造函数，Parent构造函数又调用Noncopyable的拷贝构造函数

	//Child c1;
	//Child c2(c1);
	return 0;
}