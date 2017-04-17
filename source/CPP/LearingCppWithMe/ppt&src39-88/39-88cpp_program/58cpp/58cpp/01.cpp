#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//if (instacne_ == NULL)
		//{
		//	instacne_ = new Singleton;
		//}
		//return instacne_;
		if (!instacne_.get())
		{
			instacne_ = auto_ptr<Singleton>(new Singleton);
		}

		return instacne_.get();
	}

	~Singleton()
	{
		cout<<"~Singleton ..."<<endl;
	}
private:
	// 禁止拷贝
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	// 将构造函数说明为私有的
	Singleton()
	{
		cout<<"Singleton ..."<<endl;
	}
	static auto_ptr<Singleton> instacne_;
};

auto_ptr<Singleton> Singleton::instacne_;

int main(void)
{
	//Singleton s1;
	//Singleton s2;

	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	Singleton s3(*s1);		// 调用拷贝构造函数

	return 0;
}

//class Noncopyable
//{
//protected:
//	Noncopyable() {}
//	~Noncopyable() {}
//private:
//	Noncopyable(const Noncopyable&);
//	const Noncopyable& operator=(const Noncopyable&);
//};