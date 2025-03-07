#include <iostream>
using namespace std;

int main()
{
	int map[101][101] = { 0, };

	int n, a, b, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		for (int x = a; x < a + 10; x++)
		{
			for (int y = b; y < b + 10; y++)
			{
				if (x > 100 || y > 100 || x < 1 || y < 1)
					continue;

				if (map[x][y] == 0)
				{
					map[x][y] = 1;
					count++;
				}
			}
		}
	}

	cout << count;

	return 0;
}