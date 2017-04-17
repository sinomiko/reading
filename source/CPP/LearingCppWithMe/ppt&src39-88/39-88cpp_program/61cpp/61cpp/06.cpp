#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Test
{
	int a;
	string b;
	string c;
};

int main(void)
{
	Test t1;
	t1.a = 100;
	t1.b = "abcxxxssssddddddddddddddddddddssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";
	t1.c = "yyyeeeeeeeeeeeeeeeeeeeeeeeeedddddddddddddeeeeeeeeeeeeeeeeeeeeeeddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeee";


	//ofstream fout("test6.txt", ios::out | ios::binary);
	//fout.write((char*)&t1, sizeof(t1));
	//fout.close();

	//ifstream fin("test6.txt", ios::in | ios::binary);
	//Test t2;
	//fin.read((char*)&t2, sizeof(Test));
	//cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
	//fin.close();

	//cout<<sizeof(Test)<<endl;
	//string a="ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
	//cout<<sizeof(string)<<endl;
	//cout<<sizeof(a)<<endl;

	ofstream fout("test6.txt", ios::out | ios::binary);
	//fout.write((char*)&t1, sizeof(t1));
	fout.write((char*)&t1.a, sizeof(int));
	int len;
	len = t1.b.length();
	fout.write((char*)&len, sizeof(int));
	fout.write(t1.b.data(), t1.b.length());
	len = t1.c.length();
	fout.write((char*)&len, sizeof(int));
	fout.write(t1.c.data(), t1.c.length());
	fout.close();

	ifstream fin("test6.txt", ios::in | ios::binary);
	Test t2;
	fin.read((char*)&t2.a, sizeof(int));
	fin.read((char*)&len, sizeof(int));
	t2.b.resize(len);
	fin.read(&t2.b[0], len);
	fin.read((char*)&len, sizeof(int));
	t2.c.resize(len);
	fin.read(&t2.c[0], len);


	cout<<t2.a<<" "<<t2.b<<" "<<t2.c<<endl;
	fin.close();


	return 0;
}