#include "Test.h"

int main(void)
{
	Test t;
	t.Display();

	Test t2(10);
	t2.Display();

	Test* t3 = new Test(20);	// new operator
	t3->Display();

	delete t3;

	
	return 0;
}