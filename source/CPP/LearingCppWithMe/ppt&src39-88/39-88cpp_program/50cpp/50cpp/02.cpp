#include <iostream>
using namespace std;

double Divide(double a, double b)
{
	if (b == 0.0)
	{
		throw 1;		// throw
	}
	else
		return a / b;
}

int main(void)
{
	try			// try
	{
		cout<<"division ..."<<endl;
		cout<<Divide(3.0, 0.0)<<endl;
		cout<<Divide(5.0, 0.0)<<endl;

	}
	catch (int)		// catch
	{
		cout<<"divisiong by zero"<<endl;
	}
	return 0;
}