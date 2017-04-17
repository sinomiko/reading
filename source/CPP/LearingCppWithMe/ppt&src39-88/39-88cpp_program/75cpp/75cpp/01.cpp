#include <vector>
#include <iostream>
using namespace std;

class Test
{
public:
	Test()
	{
		cout<<"Test ..."<<endl;
	}
	Test(const Test& other)
	{
		cout<<"Copy Test ..."<<endl;
	}
	~Test()
	{
		cout<<"~Test ..."<<endl;
	}
};

int main(void)
{
	vector<Test> v;
	Test t1;
	Test t2;
	Test t3;

	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	return 0;
}