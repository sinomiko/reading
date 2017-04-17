#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

bool my_greater(int a, int b)
{
	return a > b;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a+6);

	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	rotate(v.begin(), v.begin()+2, v.end()-1);
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	sort(v.begin(), v.end(), my_greater);
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	return 0;
}