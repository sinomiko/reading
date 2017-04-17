#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	//ofstream fout;
	//fout.open("test.txt");
	ofstream fout("test.txt", ios::out | ios::app);
	
	//if (fout.is_open())
	//{
	//	cout<<"succ"<<endl;
	//}
	//else
	//	cout<<"failed"<<endl;

	//if (fout.good())
	//{
	//	cout<<"succ"<<endl;
	//}
	//else
	//	cout<<"failed"<<endl;

	//if (fout)
	//{
	//	cout<<"succ"<<endl;
	//}
	//else
	//	cout<<"failed"<<endl;

	//if (!fout)
	//{
	//	cout<<"failed"<<endl;
	//}
	//else
	//	cout<<"succ"<<endl;

	assert(fout);


	fout.close();
	return 0;
}