#include <iostream>
using namespace std;

class DBHelper
{
public:
	DBHelper()
	{
		cout<<"DB ..."<<endl;
	}
	~DBHelper()
	{
		cout<<"~DB ..."<<endl;
	}

	void Open()
	{
		cout<<"Open ..."<<endl;
	}

	void Close()
	{
		cout<<"Close ..."<<endl;
	}

	void Query()
	{
		cout<<"Query ..."<<endl;
	}
};

class DB
{
public:
	DB()
	{
		db_ = new DBHelper;
	}

	~DB()
	{
		delete db_;
	}

	DBHelper* operator->()
	{
		return db_;
	}
private:
	DBHelper* db_;
};


int main(void)
{
	DB db;
	db->Open();
	db->Query();
	db->Close();


	return 0;
}