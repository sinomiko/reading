#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	//ofstream fout("test.txt", ios::out | ios::app | ios::ate);

	//assert(fout);

	ofstream fout("test.txt", ios::out | ios::app | ios::trunc);
	if (fout.good())
	{
		cout<<"good"<<endl;
	}
	if (fout.bad())
	{
		cout<<"bad"<<endl;
	}
	if (fout.fail())
	{
		cout<<"fail"<<endl;
	}
	if (fout.eof())
	{
		cout<<"eof"<<endl;
	}

	fout.clear();
	fout.open("test.txt");
	if (fout)
	{
		cout<<"open succ"<<endl;
	}
	else
		cout<<"open failed"<<endl;

	fout.close();

	return 0;
}