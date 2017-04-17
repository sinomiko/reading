#include <boost/shared_ptr.hpp>
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
};

int main(void)
{
	cout<<"Entering main ..."<<endl;
	boost::shared_ptr<X> p1(new X);
	cout<<p1.use_count()<<endl;
	boost::shared_ptr<X> p2 = p1;
	//boost::shared_ptr<X> p3;
	//p3 = p1;

	cout<<p2.use_count()<<endl;
	p1.reset();
	cout<<p2.use_count()<<endl;
	p2.reset();
	cout<<"Exiting main ..."<<endl;
	return 0;
}
