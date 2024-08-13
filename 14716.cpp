#include <iostream>
#include <queue>
using namespace std;

int m, n, ans=0;
int map[251][251] = {0, };
bool visited[251][251] = {false, };
int dy[] = { 0,0,-1,1,-1,-1,1,1 };
int dx[] = { 1,-1,0,0,-1,1,-1,1 };
queue<pair<int, int> > q;

void bfs(int y, int x) {
    visited[y][x] = true;
    q.emplace(y, x);
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx<0 || nx>=n || ny<0 || ny>=m) {
                continue;
            }
            if(map[ny][nx]==1 && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }
    }
}

int main() {
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j]==1 && !visited[i][j]) {
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}