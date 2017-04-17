#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include <deque>
using namespace std;

template <typename T, typename CONT = deque<T> >
class Stack
{
public:
	Stack() : c_()
	{
	}
	~Stack()
	{
	}

	void Push(const T& elem)
	{
		c_.push_back(elem);
	}
	void Pop()
	{
		c_.pop_back();
	}
	T& Top()
	{
		return c_.back();
	}
	const T& Top() const
	{
		return c_.back();
	}
	bool Empty() const
	{
		return c_.empty();
	}
private:
	CONT c_;
	int top_;
};

#endif // _STACK_H_