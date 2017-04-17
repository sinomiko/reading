#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(void)
{
	ifstream fin("test7.txt");
	assert(fin);
	fin.seekg(2);

	char ch;
	fin.get(ch);
	cout<<ch<<endl;

	fin.seekg(-1, ios::end);
	fin.get(ch);
	cout<<ch<<endl;

	fin.seekg(0, ios::end);
	streampos pos = fin.tellg();
	cout<<pos<<endl;

	return 0;
}