#include <iostream>

#include <string>
using namespace std;

int main()
{
	string str;

	while (true)
	{
		getline(cin, str);

		if (cin.eof())
			break;

		cout << str << '\n';
	}

	return 0;
}