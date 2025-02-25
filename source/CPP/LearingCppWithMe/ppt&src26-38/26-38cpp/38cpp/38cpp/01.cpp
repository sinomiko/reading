#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape
{
public:
	void Draw()
	{
		cout<<"Circle Draw ..."<<endl;
	}
};

class Square : public Shape
{
public:
	void Draw()
	{
		cout<<"Square Draw ..."<<endl;
	}
};

int main(void)
{
	Shape* p;
	Circle c;

	p = &c;
	p->Draw();

	if (dynamic_cast<Circle*>(p))
	{
		cout<<"p is point to a Circle object"<<endl;
		Circle* cp = dynamic_cast<Circle*>(p);		// 安全向下转型
		cp->Draw();
	}
	else if (dynamic_cast<Square*>(p))
	{
		cout<<"p is point to a Square object"<<endl;
	}
	else
	{
		cout<<"p is point to a Other object"<<endl;
	}

	cout<<typeid(*p).name()<<endl;
	cout<<typeid(Circle).name()<<endl;
	if (typeid(Circle).name() == typeid(*p).name())
	{
		cout<<"p is point to a Circle object"<<endl;
		((Circle*)p)->Draw();
	}
	else if (typeid(Square).name() == typeid(*p).name())
	{
		cout<<"p is point to a Circle object"<<endl;
		((Square*)p)->Draw();
	}
	else
	{
		cout<<"p is point to a Other object"<<endl;
	}

	return 0;
}