#include "Stack.h"
#include <iostream>
#include <vector>
using namespace std;


int main(void)
{
	/*Stack<int> s;*/
	Stack<int, vector<int> > s;
	s.Push(1);
	s.Push(2);
	s.Push(3);

	while (!s.Empty())
	{
		cout<<s.Top()<<endl;
		s.Pop();
	}
	return 0;
}