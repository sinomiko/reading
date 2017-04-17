#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

int mult(int a, int b)
{
	return a * b;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a+5);

	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	// ÀÛ¼Ó
	cout<<accumulate(v.begin(), v.end(), 0)<<endl;

	// ÀÛ³Ë
	cout<<accumulate(v.begin(), v.end(), 1, mult)<<endl;

	return 0;
}