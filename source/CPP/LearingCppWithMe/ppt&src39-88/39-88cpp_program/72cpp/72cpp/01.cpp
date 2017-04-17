#include <iostream>
using namespace std;

#include "Singleton.h"

class ApplicationImpl
{
public:
	ApplicationImpl() { cout<<"ApplicationImpl ..."<<endl; }
	~ApplicationImpl() { cout<<"~ApplicationImpl ..."<<endl; }
	void Run() { cout<<"Run ..."<<endl; }
};

typedef Singleton<ApplicationImpl> Application;

int main(void)
{
	Application::GetInstance().Run();
	Application::GetInstance().Run();
	return 0;
}