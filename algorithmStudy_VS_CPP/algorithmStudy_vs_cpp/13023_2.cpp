#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int> > graph;
vector<bool> visited;
bool result = false;

void dfs(int node, int cnt)
{
	if (cnt == 4)
	{
		result = true;
		return;
	}

	visited[node] = true;
	for (int next : graph[node])
	{
		if (!visited[next])
		{
			dfs(next, cnt + 1);
			visited[next] = false;
		}
	}
}

int main()
{
	cin >> N >> M;

	graph.resize(N);
	visited.resize(N);

	for (int i = 0; i < M; ++i)
	{
		int a, b;

		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
	{
		if (!visited[i])
		{
			dfs(i, 0);
			visited[i] = false;
		}
		if (result)
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;

	return 0;
}