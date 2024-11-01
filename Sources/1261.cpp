#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int map[101][101];
int visited[101][101];
int n, m;

void bfs() {
    queue<pair<int, int> > q;
    q.emplace(0, 0);
    visited[0][0] = 0;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(map[nx][ny] == 1) {
                if(visited[nx][ny] > visited[x][y] + 1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
            else {
                if(visited[nx][ny] > visited[x][y]) {
                    visited[nx][ny] = visited[x][y];
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            visited[i][j] = INT_MAX;
        }
    }
    bfs();
    cout << visited[n-1][m-1];

    return 0;
}