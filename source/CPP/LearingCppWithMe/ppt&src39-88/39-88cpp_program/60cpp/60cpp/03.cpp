#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	//ofstream fout1("test3.txt", ios::in | ios::out | ios::ate);
	//ofstream fout2("test3.txt", ios::in | ios::out | ios::ate);

	//ofstream fout1("test3.txt", ios::in | ios::out | ios::app);
	//ofstream fout2("test3.txt", ios::in | ios::out | ios::app);

	ofstream fout1("test3.txt", ios::in | ios::out | ios::app | ios::ate);
	ofstream fout2("test3.txt", ios::in | ios::out | ios::app | ios::ate);

	assert(fout1);
	assert(fout2);

	fout1<<"X";
	fout2<<"Y";

	fout1.close();
	fout2.close();

	return 0;
}