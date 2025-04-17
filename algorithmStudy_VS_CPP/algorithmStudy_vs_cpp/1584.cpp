#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int map[501][501];
int dist[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void makeArea(int x1, int y1, int x2, int y2, int num) {
    for(int i=min(y1, y2); i<=max(y1, y2); i++) {
        for(int j=min(x1, x2); j<=max(x1, x2); j++) {
            map[i][j] = num;
        }
    }
}

void bfs() {
    queue<pair<int, int> > q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > 500 || ny > 500)
                continue;
            if(map[nx][ny] == -1)
                continue;

            int nextCost = dist[x][y] + map[nx][ny];
            if(dist[nx][ny] > nextCost) {
                dist[nx][ny] = nextCost;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    for(int i=0; i<=500; i++) {
        for(int j=0; j<=500; j++) {
            dist[i][j] = INT_MAX;
            map[i][j] = 0;
        }
    }
    int n, m, x1, x2, y1, y2;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        makeArea(x1, y1, x2, y2, 1);
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        makeArea(x1, y1, x2, y2, -1);
    }

    bfs();

    if(dist[500][500] == INT_MAX)
        cout << -1;
    else
        cout << dist[500][500];

    return 0;
}