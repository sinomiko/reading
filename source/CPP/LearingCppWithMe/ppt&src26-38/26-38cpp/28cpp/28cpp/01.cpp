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

	ShowVec(v);

	//v.erase(remove(v.begin(), v.end(), 3), v.end());
	INTVEC::iterator it;
	for (it=v.begin(); it!=v.end(); /*++it*/)
	{
		if (*it == 3)
		{
			it = v.erase(it);	// erase返回的是当前删除元素的下一个元素
		}
		else
			++it;
	}
	ShowVec(v);

	return 0;
}