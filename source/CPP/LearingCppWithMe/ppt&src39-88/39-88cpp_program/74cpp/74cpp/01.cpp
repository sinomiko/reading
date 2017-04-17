#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
	vector<int> v;

	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;
	v.push_back(1);
	cout<<v.capacity()<<endl;

	return 0;
}
