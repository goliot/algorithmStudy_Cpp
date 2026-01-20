#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, c;
vector<int> graph;

int findParent(int node)
{
	if (node == graph[node]) return node;
	return graph[node] = findParent(graph[node]);
}

void unionSet(int u, int v)
{
	u = findParent(u);
	v = findParent(v);
	if (u == v) return;
	graph[u] = v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	graph.resize(n + 1);

	for (int i = 0; i <= n; ++i)
	{
		graph[i] = i;
	}

	while (m--)
	{
		cin >> a >> b >> c;
		if (a == 0)
		{
			unionSet(b, c);
		}
		else
		{
			if (findParent(b) == findParent(c))
			{
				cout << "YES";
			}
			else
			{
				cout << "NO";
			}
			cout << '\n';
		}
	}

	return 0;
}