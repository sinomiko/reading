#ifndef _TEST_H_
#define _TEST_H_

class Test
{
public:
	// 如果类不提供任何一个构造函数，系统将为我们提供一个不带参数的
	// 默认的构造函数
	Test();
	Test(int num);
	void Display();

	~Test();
private:
	int num_;
};
#endif // _TEST_H_