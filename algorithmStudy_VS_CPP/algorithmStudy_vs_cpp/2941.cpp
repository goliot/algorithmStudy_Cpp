#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	string cro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	string s;
	cin >> s;

	int count = 0;
	for (int i=0; i<8; i++)
	{
		size_t pos = s.find(cro[i]);
		while (pos != string::npos)
		{
			s.replace(pos, cro[i].length(), string(cro[i].length(), ' '));
			count++;
			pos = s.find(cro[i]);
		}
	}
	for (char c : s)
	{
		if (c != ' ') count++;
	}

	cout << count;

	return 0;
}