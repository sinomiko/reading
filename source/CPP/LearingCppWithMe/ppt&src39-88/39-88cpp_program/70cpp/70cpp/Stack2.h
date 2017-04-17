#ifndef _STACK2_H_
#define _STACK2_H_

#include <exception>

template <typename T, int MAX_SIZE>
class Stack2
{
public:
	Stack2();
	~Stack2();

	void Push(const T& elem);
	void Pop();
	T& Top();
	const T& Top() const;
	bool Empty() const;
private:
	T* elems_;
	int top_;
};

template <typename T, int MAX_SIZE>
Stack2<T, MAX_SIZE>::Stack2() : top_(-1)
{
	elems_ = new T[MAX_SIZE];
}

template <typename T, int MAX_SIZE>
Stack2<T, MAX_SIZE>::~Stack2()
{
	delete[] elems_;
}

template <typename T, int MAX_SIZE>
void Stack2<T, MAX_SIZE>::Push(const T& elem)
{
	if (top_ + 1 >= MAX_SIZE)
		throw out_of_range("Stack2<>::Push() Stack2 full");

	elems_[++top_] = elem;
}

template <typename T, int MAX_SIZE>
void Stack2<T, MAX_SIZE>::Pop()
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack2<>::Push() Stack2 empty");

	--top_;
}

template <typename T, int MAX_SIZE>
T& Stack2<T, MAX_SIZE>::Top()
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack2<>::Push() Stack2 empty");

	return elems_[top_];
}

template <typename T, int MAX_SIZE>
const T& Stack2<T, MAX_SIZE>::Top() const
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack2<>::Push() Stack2 empty");

	return elems_[top_];
}

template <typename T, int MAX_SIZE>
bool Stack2<T, MAX_SIZE>::Empty() const
{
	return top_ + 1 == 0;
}
#endif // _STACK2_H_