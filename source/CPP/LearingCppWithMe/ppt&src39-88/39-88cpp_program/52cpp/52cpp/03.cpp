#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
	MyException(const char* message)
		: message_(message)
	{
		cout<<"MyException ..."<<endl;
	}
	MyException(const MyException& other) : message_(other.message_)
	{
		cout<<"Copy MyException ..."<<endl;
	}
	virtual ~MyException()
	{
		cout<<"~MyException ..."<<endl;
	}

	const char* what() const
	{
		return message_.c_str();
	}
private:
	string message_;
};

class MyExceptionD : public MyException
{
public:
	MyExceptionD(const char* message)
		: MyException(message)
	{
		cout<<"MyExceptionD ..."<<endl;
	}
	MyExceptionD(const MyExceptionD& other)
		: MyException(other)
	{
		cout<<"Copy MyExceptionD ..."<<endl;
	}
	~MyExceptionD()
	{
		cout<<"~MyExceptionD ..."<<endl;
	}
};

void fun(int n) throw (int, MyException, MyExceptionD)
{
	if (n == 1)
	{
		throw 1;
	}
	else if (n == 2)
	{
		throw MyException("test exception1");
	}
	else if (n == 3)
	{
		throw MyExceptionD("test exception2");
	}
	else
		throw 1.0;
}

void fun2() throw()
{
	throw 1;
}

int main(void)
{
	try
	{
		//fun(5);
		fun2();
	}
	catch (double d)
	{
		cout<<"catch double ..."<<endl;
		cout<<"d="<<d<<endl;
	}
	catch (int n)
	{
		cout<<"catch int ..."<<endl;
		cout<<"n="<<n<<endl;
	}
	catch (MyExceptionD& e)
	{
		cout<<"catch MyExceptionD ..."<<endl;
		cout<<e.what()<<endl;
	}
	catch (MyException& e)
	{
		cout<<"catch MyException ..."<<endl;
		cout<<e.what()<<endl;
	}

	return 0;
}