#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int l, r, c;
char map[31][31][31];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int bfs(int z1, int y1, int x1, int cnt1) {
    queue<tuple<int, int, int, int> > q;
    q.emplace(z1, y1, x1, cnt1);
    bool visited[31][31][31] = {false, };

    visited[z1][y1][x1] = true;

    while(!q.empty()) {
        int z = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        int cnt = get<3>(q.front());
        if(map[z][y][x] == 'E') {
            return cnt;
        }
        q.pop();

        for(int i=0; i<6; i++) {
            int nz = dz[i] + z;
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if(nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l)
                continue;
            if(map[nz][ny][nx] == '#') continue;
            if(visited[nz][ny][nx]) continue;

            visited[nz][ny][nx] = true;
            q.emplace(nz, ny, nx, cnt + 1);
        }
    }
    return -1;
}

int main() {
    while(true) {
        int sx, sy, sz;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> map[i][j][k];
                    if(map[i][j][k] == 'S') {
                        sz = i;
                        sy = j;
                        sx = k;
                    }
                }
            }
        }
        int res = bfs(sz, sy, sx, 0);
        if(res == -1) cout << "Trapped!" << '\n';
        else cout << "Escaped in " << res << " minute(s)." << '\n';
    }

    return 0;
}