#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, k, ans = 0;
int visited[1001][1001][11] = {0, };
int map[1001][1001] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct t {
    int x, y, z;
};

int bfs() {
    queue<t> q;
    visited[0][0][0] = 1;
    q.push({0, 0, 0});
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
        if(x == n-1 && y == m-1) return visited[x][y][z];
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int bl = z;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][bl]) continue;
            if(map[nx][ny] == 0) {
                visited[nx][ny][bl] = visited[x][y][bl] + 1;
                q.push({nx, ny, bl});
            }
            if(map[nx][ny] == 1 && bl < k) {
                if(visited[nx][ny][bl+1]) continue;
                visited[nx][ny][bl+1] = visited[x][y][bl] + 1;
                q.push({nx, ny, bl + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m >> k;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    cout << bfs();
    return 0;
}