#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream fout("test2.txt");
	assert(fout);
	char ch;

	for (int i=0; i<26; i++)
	{
		ch = 'A' + i;
		fout.put(ch);
	}
	fout.close();

	ifstream fin("test2.txt");
	while (fin.get(ch))
	{
		cout<<ch;
	}
	cout<<endl;

	return 0;
}