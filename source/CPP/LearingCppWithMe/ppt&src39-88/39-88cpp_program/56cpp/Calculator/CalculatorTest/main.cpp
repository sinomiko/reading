#include <iostream>
using namespace std;

#include "DebugNew.h"
#include "Node.h"

int main(void)
{
	//int* p = new int;
	////delete p;

	//int* p2 = new int[5];
	////delete[] p2;
	NodePtr np(new Node);
	np->Calc();

	NodePtr np2(np);
	NodePtr np3;
	np3 = np2;


	return 0;
}
