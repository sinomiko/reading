#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

int main(void)
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a+4);
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	while (next_permutation(v.begin(), v.end()))
	{
		for_each(v.begin(), v.end(), print_element);
		cout<<endl;
	}


	return 0;
}