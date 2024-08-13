#include <iostream> //7576
#include <algorithm>
#include <queue>
using namespace std;

int m, n;
int map[1001][1001];
bool visited[1001][1001];
int path[1001][1001];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int> > q;

void bfs() {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(map[ny][nx]==0 && visited[ny][nx]==0) {
                visited[ny][nx] = true;
                q.emplace(ny, nx);
                path[ny][nx] = path[y][x] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==1) {
                q.emplace(i, j);
            }
        }
    }

    bfs();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j]==0 && path[i][j]==0) {
                cout << -1;
                return 0;
            }
        }
    }

    int ans = -1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(path[i][j] > ans) {
                ans = path[i][j];
            }
        }
    }
    cout << ans;

    return 0;
}
