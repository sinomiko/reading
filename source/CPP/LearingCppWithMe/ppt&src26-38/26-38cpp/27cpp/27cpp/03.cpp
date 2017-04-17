#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


typedef vector<int> INTVEC;

void ShowVec(const INTVEC& v)
{
	INTVEC::const_iterator it;
	for (it=v.begin(); it!=v.end(); ++it)
	{
		cout<<*it<<" ";
	}

	cout<<endl;
}

int main(void)
{
	INTVEC v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	//cout<<v.back()<<endl;
	//v.pop_back();

	ShowVec(v);

	//v.erase(v.begin()+2);
	//v.erase(v.begin(), v.begin()+2);

	v.erase(remove(v.begin(), v.end(), 3), v.end());
	ShowVec(v);



	return 0;
}