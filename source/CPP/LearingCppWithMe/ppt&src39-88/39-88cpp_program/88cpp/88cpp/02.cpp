#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <iostream>
using namespace std;

class Parent;
class Child;
typedef boost::shared_ptr<Parent> parent_ptr;
typedef boost::shared_ptr<Child> child_ptr;

class Child
{
public:
	Child() { cout<<"Child ..."<<endl; }
	~Child() { cout<<"~Child ..."<<endl; }
	parent_ptr parent_;
};

class Parent
{
public:
	Parent() { cout<<"Parent ..."<<endl; }
	~Parent() { cout<<"~Parent ..."<<endl; }
	boost::weak_ptr<Child> child_;
};

int main(void)
{
	parent_ptr parent(new Parent);
	child_ptr child(new Child);
	parent->child_ = child;
	child->parent_ = parent;
	return 0;
}
