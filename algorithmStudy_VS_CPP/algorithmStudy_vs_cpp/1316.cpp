#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<char> cSet;

	string s;
	int n, res = 0;
	cin >> n;
	while (n--)
	{
		unordered_set<char> cSet;

		cin >> s;
		bool flag = true;
		for (int i=0; i<s.length(); i++)
		{
			if (i == 0)
			{
				cSet.insert(s[i]);
				continue;
			}

			if (s[i] != s[i - 1] && cSet.find(s[i]) != cSet.end())
			{
				flag = false;
				break;
			}
			else
			{
				cSet.insert(s[i]);
			}
		}

		if (flag)
			res++;
	}

	cout << res;

	return 0;
}