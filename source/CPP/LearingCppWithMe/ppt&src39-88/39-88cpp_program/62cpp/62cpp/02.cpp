#include <iostream>
#include <sstream>

using namespace std;

string doubletostr(double val)
{
	ostringstream oss;
	oss<<val;

	return oss.str();
}

double strtodouble(const string& str)
{
	istringstream iss(str);
	double val;
	iss>>val;
	return val;
}

int main(void)
{
	double val = 55.55;

	string str = doubletostr(val);
	cout<<str<<endl;

	str = "123.123";
	val = strtodouble(str);
	cout<<val<<endl;
	return 0;

}