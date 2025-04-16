#include <iostream>
using namespace std;

int parent[201];

int find(int x)
{
	if (parent[x] != x)
	{
		parent[x] = find(parent[x]);
	}

	return parent[x];
}

void unionSet(int a, int b)
{
	int rootA = find(a);
	int rootB = find(b);
	if (rootA != rootB)
	{
		parent[rootB] = rootA;
	}
}

bool isConnected(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	int n, m, a, b, c, x;
	cin >> n;
	cin >> m;

	for (int i = 0; i < 201; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> x;
			if (x == 1)
			{
				unionSet(i, j);
			}
		}
	}

	int cur = 0;
	cin >> cur;
	for (int i = 1; i < m; i++)
	{
		cin >> x;
		if (!isConnected(cur, x))
		{
			cout << "NO";
			return 0;
		}
		else
		{
			cur = x;
		}
	}
	cout << "YES";

	return 0;
}