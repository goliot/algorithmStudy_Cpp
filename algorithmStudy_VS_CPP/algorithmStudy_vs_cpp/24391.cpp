#include <iostream>
#include <vector>
using namespace std;

int cur = 0;
int parent[100001] = { 0, };

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
	int n, m, res = 0;
	cin >> n >> m;

	for (int i = 0; i <= 100000; i++)
	{
		parent[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		unionSet(a, b);
	}

	int x;
	cin >> cur;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (!isConnected(cur, x)) {
			res++;
		}
		cur = x;
	}

	cout << res;
	return 0;
}