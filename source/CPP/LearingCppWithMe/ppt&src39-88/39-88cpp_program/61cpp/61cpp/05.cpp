#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(void)
{
	ofstream fout("test5.txt", ios::out | ios::binary);
	fout<<"abc"<<200;

	return 0;
}