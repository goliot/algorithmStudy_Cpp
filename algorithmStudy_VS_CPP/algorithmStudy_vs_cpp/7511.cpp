#include <iostream>
using namespace std;

int parent[1000001];

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
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		cout << "Scenario " << test + 1 << ":" << '\n';

		for (int i = 0; i < 1000001; i++)
		{
			parent[i] = i;
		}

		int n, k;
		cin >> n;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			unionSet(a, b);
		}
		int m;
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			cout << (isConnected(u, v) ? 1 : 0) << '\n';
		}

		cout << '\n';
	}

	return 0;
}