#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <fstream>
#include <string>
class Serializer
{
public:
	Serializer(const std::string& fileName);
	Serializer& Put(int x);
	Serializer& Put(unsigned int x);
	Serializer& Put(long x);
	Serializer& Put(unsigned long x);
	Serializer& Put(const std::string& x);
	Serializer& Put(bool x);

	Serializer& operator<<(int x);
	Serializer& operator<<(unsigned int x);
	Serializer& operator<<(long x);
	Serializer& operator<<(unsigned long x);
	Serializer& operator<<(const std::string& x);
	Serializer& operator<<(bool x);

private:
	std::ofstream stream_;
};

class DeSerializer
{
public:
	DeSerializer(const std::string& fileName);
	DeSerializer& Get(int& x);
	DeSerializer& Get(unsigned int& x);
	DeSerializer& Get(long& x);
	DeSerializer& Get(unsigned long& x);
	DeSerializer& Get(std::string& x);
	DeSerializer& Get(bool& x);

	DeSerializer& operator>>(int& x);
	DeSerializer& operator>>(unsigned int& x);
	DeSerializer& operator>>(long& x);
	DeSerializer& operator>>(unsigned long& x);
	DeSerializer& operator>>(std::string& x);
	DeSerializer& operator>>(bool& x);

private:
	std::ifstream stream_;
};
#endif // _SERIAL_H_