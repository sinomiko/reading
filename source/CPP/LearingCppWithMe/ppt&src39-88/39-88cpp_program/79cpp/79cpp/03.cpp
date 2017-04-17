#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

bool fun(int a)
{
	return a < 10;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 3 };
	vector<int> v(a, a+5);
	list<int> l(5);

	replace(v.begin(), v.end(), 3, 13);
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	replace_copy(v.begin(), v.end(), l.begin(), 13, 3);
	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	for_each(l.begin(), l.end(), print_element);
	cout<<endl;

	replace_copy_if(v.begin(), v.end(), l.begin(), fun, 0);
	for_each(l.begin(), l.end(), print_element);
	cout<<endl;



	return 0;
}