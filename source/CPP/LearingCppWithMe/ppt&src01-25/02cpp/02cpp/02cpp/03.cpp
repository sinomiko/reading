#include <iostream>
using namespace std;

#define STR(a) #a
#define CAT(a,b) a##b

int main(void)
{
	int xy = 100;
	cout<<STR(ABCD)<<endl;			//#ABCD <=> "ABCD"
	cout<<CAT(x, y)<<endl;			//x##y  <=> xy
	return 0;
}