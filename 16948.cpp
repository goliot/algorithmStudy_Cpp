#include <iostream>
#include <queue>
using namespace std;

int n;
int map[201][201];
bool visited[201][201];
int dy[] = {-1, 1, -2, 2, -1, 1};
int dx[] = {-2, -2, 0, 0, 2, 2};

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    map[y][x] = 0;
    visited[y][x] = true;
    q.emplace(y, x);
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny<0 || nx<0 || ny>n || nx>n) continue;
            if(!visited[ny][nx]) {
                visited[ny][nx] = true;
                map[ny][nx] = map[y][x] + 1;
                q.emplace(ny, nx);
            }
        }
    }
}

int main() {
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bfs(b, a);

    if(map[d][c]==0) cout << -1;
    else cout << map[d][c];

    return 0;
}