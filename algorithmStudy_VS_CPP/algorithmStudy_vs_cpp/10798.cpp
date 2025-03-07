#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> v;
	string s;

	string res = "";
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		while (s.size() < 15)
		{
			s += ' ';
		}
		v.push_back(s);
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(v[j][i] != ' ')
				res += v[j][i];
		}
	}
	cout << res;

	return 0;
}