#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge> > graph;
vector<bool> visited;
vector<int> m_distance;

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (edge i : graph[cur])
		{
			if (!visited[i.first])
			{
				visited[i.first] = true;
				q.push(i.first);
				m_distance[i.first] = m_distance[cur] + i.second;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	graph.resize(n + 1);
	m_distance = vector<int>(n + 1, 0);
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < n; ++i)
	{
		int start;
		cin >> start;
		while (true)
		{
			int end, value;
			cin >> end;
			if (end == -1)
			{
				break;
			}
			cin >> value;
			graph[start].push_back(edge(end, value));
		}
	}

	bfs(1);
	int Max = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (m_distance[Max] < m_distance[i])
		{
			Max = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);
	bfs(Max);

	sort(m_distance.begin(), m_distance.end());
	cout << m_distance[n];

	return 0;
}