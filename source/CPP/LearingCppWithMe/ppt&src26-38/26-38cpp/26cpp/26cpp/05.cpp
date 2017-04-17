#include <string>
#include <iostream>
using namespace std;
int main()
{
	string strinfo=" //*---Hello World!......------";
	string strset= "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string::size_type first = strinfo.find_first_of(strset);
	if(first == string::npos) 
		cout<<"not find any characters"<<endl; 
	string::size_type last = strinfo.find_last_of(strset);
	if(last == string::npos)
		cout<<"not find any characters"<<endl;
	cout << strinfo.substr(first, last - first + 1)<<endl;
	return 0;
}
