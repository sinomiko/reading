#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
	string line;
	string word;

	while (getline(cin, line))
	{
		istringstream iss(line);

		while (iss>>word)			// sscanf
			cout<<word<<"#";
		cout<<endl;
	}
	return 0;
}