#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, res = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<vector<int> > map(301, vector<int>(301, 0));

void bfs(int a, int b, bool (&visited)[301][301]) {
    queue<pair<int, int> > q;
    q.emplace(a, b);
    visited[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

void melt() {
    vector<vector<int> > nextMap = map;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int cnt = 0;
            if(map[i][j] == 0) continue;

            for(int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(map[nx][ny] == 0) cnt++;
            }
            nextMap[i][j] -= cnt;
            if(nextMap[i][j] < 0) nextMap[i][j] = 0;
        }
    }
    map = nextMap;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    int landCount = 0;
    melt();
    while(landCount <= 1) {
        landCount = 0;
        bool visited[301][301] = {false, };
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(map[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j, visited);
                    landCount++;
                }
            }
        }
        res++;
        if(landCount == 0) {
            res = 0;
            break;
        }
        melt();
    }

    cout << res;
    return 0;
}