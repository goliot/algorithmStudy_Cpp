#include <iostream> //7569
#include <queue>
#include <algorithm>
using namespace std;

int m, n, h;
int map[101][101][101];
int dist[101][101][101];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int> > q;

void bfs() {
    while(!q.empty()) {
        int a = q.front().first.first;
        int b = q.front().first.second;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<6; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            int nz = c + dz[i];
            if(nx<0 || ny<0 || nz<0 || nx>=n || ny>=m || nz>=h) continue;
            if(dist[nx][ny][nz] >= 0) continue;
            q.emplace(make_pair(nx, ny), nz);
            dist[nx][ny][nz] = dist[a][b][c] + 1;
        }
    }
}

int main() {
    cin >> m >> n >> h;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> map[i][j][k];
                if(map[i][j][k] == 1) {
                    q.emplace(make_pair(i, j),k);
                } if(map[i][j][k] == 0) {
                    dist[i][j][k] = -1;
                }
            }
        }
    }

    bfs();
    int ans = 0;
    for(int k=0; k<h; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dist[i][j][k] == -1) {
                    cout << "-1";
                    return 0;
                }
                ans = max(dist[i][j][k], ans);
            }
        }
    }
    cout << ans;

    return 0;
}