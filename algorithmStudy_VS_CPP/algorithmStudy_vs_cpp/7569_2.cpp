#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
	int z;
	int y;
	int x;
	node(int z, int y, int x) : z(z), y(y), x(x) {}
};

int m, n, h;
int ans = -1;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
vector<vector<vector<int>>> board;
vector<vector<vector<int>>> dist;
vector<vector<vector<bool>>> visited;
queue<node> q;

void bfs()
{
	while (!q.empty())
	{
		node point = q.front();
		int z = point.z;
		int y = point.y;
		int x = point.x;
		q.pop();

		for (int i = 0; i < 6; ++i)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m || visited[nz][ny][nx] || board[nz][ny][nx] != 0)
			{
				continue;
			}
			visited[nz][ny][nx] = true;
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			q.emplace(nz, ny, nx);
		}
	}
}

int main()
{
	cin >> m >> n >> h;
	board.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	dist.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	visited.assign(h, vector<vector<bool>>(n, vector<bool>(m, false)));

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
				{
					q.emplace(i, j, k);
					visited[i][j][k] = true;
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (board[i][j][k] == 0 && dist[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}

				ans = max(ans, dist[i][j][k]);
			}
		}
	}

	cout << ans;

	return 0;
}