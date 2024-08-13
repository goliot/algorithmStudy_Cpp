#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int n, m, ans=0;
int map[51][51];
bool visited[51][51];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector<pair<int, int> > v;

int bfs(int a, int b) {
    queue<pair<pair<int, int>, int> > q;
    q.push({{a, b}, 0});
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(map[x][y]==1) return cnt;

        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m) {
                if(!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, cnt+1});
                }
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) {
                v.emplace_back(i, j);
            }
        }
    }

    for(auto & i : v) {
        memset(visited, false, sizeof(visited));
        int x = i.first;
        int y = i.second;

        int tmp = bfs(x, y);
        if(tmp > ans) ans = tmp;
    }

    cout << ans;

    return 0;
}