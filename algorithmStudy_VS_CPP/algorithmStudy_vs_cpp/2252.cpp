#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> indegree(n+1, 0);
	vector<vector<int> > graph(n+1);
	queue<int> q;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	for (int i=1; i<=n; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int next : graph[cur])
		{
			indegree[next]--;
			if (indegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	return 0;
}