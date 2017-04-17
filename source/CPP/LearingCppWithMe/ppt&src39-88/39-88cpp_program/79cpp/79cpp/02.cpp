#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void print_element(int n)
{
	cout<<n<<' ';
}

int fun(int a)
{
	return 2 * a;
}

int fun2(int a, int b)
{
	return a + b;
}

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a+5);

	list<int> l(5);
	list<int> l2(2);

	transform(v.begin(), v.end(), l.begin(), fun);
	for_each(l.begin(), l.end(), print_element);
	cout<<endl;

	transform(v.begin(), v.begin()+2, v.begin()+3,l2.begin(), fun2);
	for_each(l2.begin(), l2.end(), print_element);
	cout<<endl;

	return 0;
}