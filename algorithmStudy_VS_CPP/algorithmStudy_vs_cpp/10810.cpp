#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, i, j, k;

	cin >> n >> m;
	vector<int> basket(n + 1, 0);

	while (m--)
	{
		cin >> i >> j >> k;

		for (int idx = i; idx <= j; idx++)
		{
			basket[idx] = k;
		}
	}

	for (int idx = 1; idx <= n; idx++)
	{
		cout << basket[idx] << " ";
	}

	return 0;
}