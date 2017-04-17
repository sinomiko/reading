#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>
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
	//vector<auto_ptr<X> > v;
	//auto_ptr<X> p(new X);
	//v.push_back(p);

	vector<boost::shared_ptr<X> > v;
	boost::shared_ptr<X> p(new X);
	v.push_back(p);
	cout<<p.use_count()<<endl;

	return 0;
}
