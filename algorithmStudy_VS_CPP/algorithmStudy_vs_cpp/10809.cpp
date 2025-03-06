#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	for (int i = (int)'a'; i <= (int)'z'; i++)
	{
		if (str.find((char)i) != string::npos) 
		{
			cout << str.find(char(i)) << " ";
		}
		else 
		{
			cout << -1 << " ";
		}
	}
}