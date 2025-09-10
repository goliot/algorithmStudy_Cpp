#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int t, l, curX, curY, targetX, targetY;
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
vector<vector<int>> dist;
vector<vector<bool>> visited;

void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.emplace(a, b);
    visited[a][b] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (x == targetX && y == targetY)
        {
            cout << dist[x][y] << '\n';
            return;
        }
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= l || ny >= l || visited[nx][ny])
            {
                continue;
            }

            q.emplace(nx, ny);
            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

void reset(int l) {
    visited.assign(l, vector<bool>(l, false));
    dist.assign(l, vector<int>(l, 0));
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> l;
        reset(l);
        cin >> curX >> curY;
        cin >> targetX >> targetY;
        bfs(curX, curY);
    }

    return 0;
}