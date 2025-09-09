#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int max_size = 0;
int picture_count = 0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[501][501];
bool visited[501][501];
int n, m;

int bfs(int x, int y)
{
	int size = 1;
	queue<pair<int, int> > q;
	q.emplace(x, y);
	visited[x][y] = true;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || board[nx][ny] != 1)
			{
				continue;
			}
			size++;
			q.emplace(nx, ny);
			visited[nx][ny] = true;
		}
	}

	return size;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1 && !visited[i][j])
			{
				max_size = max(max_size, bfs(i, j));
				picture_count++;
			}
		}
	}

	cout << picture_count << '\n' << max_size;
	return 0;
}