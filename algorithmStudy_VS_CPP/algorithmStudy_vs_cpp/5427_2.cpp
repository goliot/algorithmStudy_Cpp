#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int t, w, h;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<char>> building;
queue<pair<int, int> > fire;
queue<pair<int, int> > player;

void moveFire()
{
	int cnt = (int)fire.size();
	for (int i = 0; i < cnt; ++i)
	{
		int x = fire.front().first;
		int y = fire.front().second;
		fire.pop();
		for (int j = 0; j < 4; ++j)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w || building[nx][ny] != '.')
			{
				continue;
			}

			building[nx][ny] = '*';
			fire.emplace(nx, ny);
		}
	}
}

int movePlayer()
{
	int time = 0;
	while (!player.empty())
	{
		time++;
		moveFire();
		int cnt = (int)player.size();
		for (int i = 0; i < cnt; ++i)
		{
			int x = player.front().first;
			int y = player.front().second;
			player.pop();
			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)
				{
					return time;
				}
				if (building[nx][ny] != '.')
				{
					continue;
				}

				building[nx][ny] = '@';
				player.emplace(nx, ny);
			}
		}
	}

	return -1;
}

void reset(int w, int h)
{
	while (!fire.empty()) fire.pop();
	while (!player.empty()) player.pop();
	building.assign(h, vector<char>(w, '.'));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t;
	while (t--)
	{
		cin >> w >> h;
		reset(w, h);
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> building[i][j];
				if (building[i][j] == '*')
				{
					fire.emplace(i, j);
				}
				else if (building[i][j] == '@')
				{
					player.emplace(i, j);
				}
				else
				{
					continue;
				}
			}
		}

		int res = movePlayer();
		if (res == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << res << '\n';
	}

	return 0;
}