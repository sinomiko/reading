#include "Test.h"

int main(void)
{
	Test t(10);
	//Test t2(t);		// 调用拷贝构造函数
	Test t2 = t;		// 等价于Test t2(t);

	return 0;
}