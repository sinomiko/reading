#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream fout("test.txt");
	fout<<"abc"<<" "<<200;
	fout.close();

	ifstream fin("test.txt");
	string s;
	int n;
	//fin>>n>>s;
	fin>>s>>n;
	cout<<s<<" "<<n<<endl;

	return 0;
}