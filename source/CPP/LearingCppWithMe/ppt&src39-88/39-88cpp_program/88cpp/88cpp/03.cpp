#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/scoped_ptr.hpp>
#include <iostream>
using namespace std;

class X
{
public:
	X()
	{
		cout<<"X ..."<<endl;
	}
	~X()
	{
		cout<<"~X ..."<<endl;
	}

	void Fun()
	{
		cout<<"Fun ..."<<endl;
	}
};
int main(void)
{
	boost::weak_ptr<X> p;
	{
		boost::shared_ptr<X> p2(new X);
		cout<<p2.use_count()<<endl;
		p = p2;
		cout<<p2.use_count()<<endl;

		boost::shared_ptr<X> p3 = p.lock();
		if (!p3)
			cout<<"object is destroyed"<<endl;
		else
			p3->Fun();
	}
	boost::shared_ptr<X> p4 = p.lock();
	if (!p4)
		cout<<"object is destroyed"<<endl;
	else
		p4->Fun();


	boost::scoped_array<X> xx(new X[3]);
	return 0;
}