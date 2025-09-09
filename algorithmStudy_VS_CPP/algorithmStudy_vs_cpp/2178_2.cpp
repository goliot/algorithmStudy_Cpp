#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dist[101][101];
bool visited[101][101];
int board[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs()
{
	queue<pair<int, int> > q;
	visited[0][0] = true;
	dist[0][0] = 1;
	q.emplace(0, 0);
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || board[nx][ny] != 1)
			{
				continue;
			}

			visited[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.emplace(nx, ny);
		}
	}

	return dist[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	cout << bfs();
	return 0;
}