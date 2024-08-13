#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, t, ans = 0;
int map[101][101] = {0, };
int cnt[101][101];
bool visited[101][101] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int a, int b) {
    queue<pair<int, int> > q;
    q.emplace(a, b);
    visited[a][b] = true;
    int target = 987654321;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==n-1 && y==m-1) return min(target, cnt[x][y]);
        if(map[x][y]==2) {
            target = cnt[x][y] + (n-1) - x + (m-1) - y;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(visited[nx][ny]) continue;
            if(map[nx][ny]==1) continue;

            q.emplace(nx, ny);
            visited[nx][ny] = true;
            cnt[nx][ny] = cnt[x][y] + 1;
        }
    }

    if(target != 987654321) return target;
    else return -1;
}

int main() {
    cin >> n >> m >> t;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    ans = bfs(0, 0);
    if(ans == -1) cout << "Fail";
    else {
        if(ans <= t) cout << ans;
        else cout << "Fail";
    }

    return 0;
}