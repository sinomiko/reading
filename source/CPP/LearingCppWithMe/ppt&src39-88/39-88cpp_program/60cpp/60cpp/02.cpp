#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream fin("test2.txt");


	assert(fin);


	fin.close();
	return 0;
}