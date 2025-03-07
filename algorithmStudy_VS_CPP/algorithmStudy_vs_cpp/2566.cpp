#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	pair<int, int> pos = { 1, 1 };
	int res = 0;

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> x;
			if (x > res)
			{
				res = x;
				pos = { i, j };
			}
		}
	}

	cout << res << '\n' << pos.first << " " << pos.second;

	return 0;
}