#include <iostream>
using namespace std;

int main()
{
	int t, n;
	string s;

	cin >> t;
	while (t--)
	{
		cin >> n >> s;

		string tmp = "";

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < n; j++) 
			{
				tmp += s[i];
			}
		}

		cout << tmp << '\n';
	}

	return 0;
}