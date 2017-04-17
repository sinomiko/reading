#ifndef _STACK_H_
#define _STACK_H_

#include <exception>

template <typename T>
class Stack
{
public:
	explicit Stack(int maxSize);
	~Stack();

	void Push(const T& elem);
	void Pop();
	T& Top();
	const T& Top() const;
	bool Empty() const;
private:
	T* elems_;
	int maxSize_;
	int top_;
};

template <typename T>
Stack<T>::Stack(int maxSize) : maxSize_(maxSize), top_(-1)
{
	elems_ = new T[maxSize_];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] elems_;
}

template <typename T>
void Stack<T>::Push(const T& elem)
{
	if (top_ + 1 >= maxSize_)
		throw out_of_range("Stack<>::Push() stack full");

	elems_[++top_] = elem;
}

template <typename T>
void Stack<T>::Pop()
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack<>::Push() stack empty");

	--top_;
}

template <typename T>
T& Stack<T>::Top()
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack<>::Push() stack empty");

	return elems_[top_];
}

template <typename T>
const T& Stack<T>::Top() const
{
	if (top_ + 1 == 0)
		throw out_of_range("Stack<>::Push() stack empty");

	return elems_[top_];
}

template <typename T>
bool Stack<T>::Empty() const
{
	return top_ + 1 == 0;
}
#endif // _STACK_H_