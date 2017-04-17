#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

void add_3(int& n)
{
	n += 3;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a+5);
	list<int> l(15);

	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	for_each(v.begin(), v.end(), add_3);

	for_each(v.begin(), v.end(), print_element);
	cout<<endl;

	for_each(l.begin(), l.end(), print_element);
	cout<<endl;

	copy(v.begin(), v.end(), l.begin());
	for_each(l.begin(), l.end(), print_element);
	cout<<endl;

	copy_backward(v.begin(), v.end(), l.end());
	for_each(l.begin(), l.end(), print_element);
	cout<<endl;

	return 0;
}