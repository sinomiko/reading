#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class Singleton
{
public:
	static T& GetInstance()
	{
		Init();
		return *instance_;
	}

private:
	static void Init()
	{
		if (instance_ == 0)
		{
			instance_ = new T;
			atexit(Destroy);
		}
	}
	static void Destroy()
	{
		delete instance_;
	}
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	Singleton();
	~Singleton();

	static T* instance_;
};

template <typename T>
T* Singleton<T>::instance_ = 0;

#endif // _SINGLETON_H_