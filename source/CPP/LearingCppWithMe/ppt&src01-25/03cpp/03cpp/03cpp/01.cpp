#include <iostream>
using namespace std;

int var = 100;
int main(void)
{
	int var = 50;
	cout<<var<<endl;
	cout<<::var<<endl;
	return 0;
}