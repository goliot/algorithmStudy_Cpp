#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int ans = -1;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int> > q;
vector<vector<int> > board;
vector<vector<bool> > visited;
vector<vector<int> > dist;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n|| ny >= m || visited[nx][ny] || board[nx][ny] != 0)
			{
				continue;
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.emplace(nx, ny);
			visited[nx][ny] = true;
		}
	}
}

int main()
{
	cin >> m >> n;
	board.assign(n, vector<int>(m));
	dist.assign(n, vector<int>(m));
	visited.assign(n, vector<bool>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.emplace(i, j);
				visited[i][j] = true;
				dist[i][j] = 0;
			}
		}
	}

	bfs();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 0 && dist[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}

	cout << ans;
	return 0;
}