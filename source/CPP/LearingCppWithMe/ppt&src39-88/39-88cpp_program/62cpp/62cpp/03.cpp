#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
	//miniftpd项目实战

	//192,168,0,100;			sscanf
	//sprintf;


	//istringstream iss("192,168,0,100");
	//int v1;
	//int v2;
	//int v3;
	//int v4;
	//char ch;
	//iss>>v1>>ch>>v2>>ch>>v3>>ch>>v4;

	//ch = '.';
	//ostringstream oss;
	//oss<<v1<<ch<<v2<<ch<<v3<<ch<<v4;

	//cout<<oss.str()<<endl;

	string buf("192,168,0,100");
	stringstream ss(buf);
	int v1;
	int v2;
	int v3;
	int v4;
	char ch;
	ss>>v1>>ch>>v2>>ch>>v3>>ch>>v4;

	ch = '.';
	stringstream ss2;
	ss2<<v1<<ch<<v2<<ch<<v3<<ch<<v4;

	cout<<ss2.str()<<endl;


		
	return 0;

}