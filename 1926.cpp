#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, s=1;
int map[501][501];
bool visited[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > q;
vector<int> v;

void bfs(int y, int x) {
    visited[y][x] = true;
    q.emplace(y, x);
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m) {
                continue;
            }
            if(map[ny][nx]==1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                s++;
                q.emplace(ny, nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                v.push_back(s);
                cnt++;
                s = 1;
            }
        }
    }

    sort(v.begin(), v.end(), greater<>());

    cout << cnt << '\n';
    if(cnt == 0) {
        cout << 0 << '\n';
    } else {
        cout << v[0] << '\n';
    }

    return 0;
}