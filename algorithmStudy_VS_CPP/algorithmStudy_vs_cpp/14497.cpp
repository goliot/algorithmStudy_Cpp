#include <iostream>
#include <queue>
using namespace std;

char c;
int n, m, x1, y1, x2, y2, cnt = 0;
bool flag = false;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map[301][301];

void bfs(int x, int y) {
    bool visited[301][301] = {false, };
    queue<pair<int, int> > q;
    q.emplace(x, y);
    visited[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(map[nx][ny] == '#') {
                flag = true;
                return;
            }
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || !visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            if(map[nx][ny] == '1') map[nx][ny] = '0';
            else if(map[nx][ny] == '0') q.emplace(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    while(true) {
        cnt++;
        bfs(y1, x1);
        if(flag) break;
    }

    cout << cnt;

    return 0;
}