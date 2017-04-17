#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
	ofstream fout("test3.txt", ios::out | ios::binary);
	fout<<"ABC\r\n";
	fout.close();

	return 0;
}