#include <iostream>
#include <algorithm>
using namespace std;

int arr[102][102];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	int n, m;
	cin >> n >> m;

	int res = n * m * 2;

	for (int i = 0; i <= 101; i++)
	{
		for (int j = 0; j <= 101; j++)
		{
			arr[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (arr[i][j] >= arr[nx][ny])
				{
					res += arr[i][j] - arr[nx][ny];
				}
			}
		}
	}

	cout << res;

	return 0;
}