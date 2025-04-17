#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[51][51];
int path[51][51];
bool visited[51][51];
int n, m, cnt=0, ans=0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int> > q;

int bfs(int y, int x) {
    path[y][x] = 1;
    visited[y][x] = true;
    q.emplace(y, x);
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m)
                continue;
            if(map[ny][nx]==1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                path[ny][nx] = path[y][x] + 1;
                q.emplace(ny, nx);
                cnt = max(cnt, path[ny][nx]);
            }
        }
    }
    return cnt - 1;
}

void reset() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = false;
            path[i][j] = 0;
        }
    }
    cnt = 0;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            if(c=='L') map[i][j] = 1;
            else map[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==1) {
                int tmp = bfs(i, j);
                ans = max(ans, tmp);
                reset();
            }
        }
    }
    cout << ans;

    return 0;
}