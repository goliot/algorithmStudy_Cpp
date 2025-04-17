#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001][2] = {false, };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push({{0, 0}, {0, 1}});
    visited[0][0][0] = true;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(x==n-1 && y==m-1) return cnt;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m) {
                if(map[nx][ny]==1 && b==0) {
                    visited[nx][ny][b+1] = true;
                    q.push({{nx, ny}, {b+1, cnt+1}});
                }
                else if(map[nx][ny]==0 && !visited[nx][ny][b]) {
                    visited[nx][ny][b] = true;
                    q.push({{nx, ny}, {b, cnt+1}});
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    cout << bfs();

    return 0;
}