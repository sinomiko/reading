#include <iostream>
using namespace std;


template <typename T>
class MyClass
{
private:
	T value;
public:
	void Assign(const MyClass<T>& x)
	{
		value = x.value;
	}
};

int main(void)
{
	MyClass<double> d;
	MyClass<int> i;

	d.Assign(d);		// OK
	d.Assign(i);		// Error
	return 0;
}

