#include "Test.h"

int main(void)
{
	Test t;
	t.~Test();		// 析构函数可以显式调用，但一般很少用。
	return 0;
}