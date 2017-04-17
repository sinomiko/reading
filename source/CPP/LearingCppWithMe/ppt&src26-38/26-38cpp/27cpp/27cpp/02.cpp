#include <vector>
#include <iostream>
using namespace std;


typedef vector<int> INTVEC;

//void ShowVec(const INTVEC& v)
//{
//	unsigned int i;
//	for (i=0; i<v.size(); i++)
//	{
//		cout<<v[i]<<" ";
//	}
//	cout<<endl;
//}


//void ShowVec(INTVEC& v)
//{
//	INTVEC::iterator it;
//	for (it=v.begin(); it!=v.end(); ++it)
//	{
//		cout<<*it<<" ";
//	}
//
//	cout<<endl;
//}

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

	ShowVec(v);

	

	return 0;
}