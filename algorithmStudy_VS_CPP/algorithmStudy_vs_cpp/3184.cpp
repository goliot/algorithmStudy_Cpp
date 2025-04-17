#include <iostream>
#include <queue>
using namespace std;

int r, c, wolf, sheep;
char map[251][251];
bool visited[251][251];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int y, int x) {
    int w=0, s=0;
    queue<pair<int, int> > q;
    q.emplace(y, x);
    visited[y][x] = true;
    if(map[y][x]=='v') w++;
    else if(map[y][x]=='o') s++;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || nx<0 || ny>=r || nx>=c) continue;
            if(visited[ny][nx] || map[ny][nx]=='#') continue;

            visited[ny][nx] = true;
            if(map[ny][nx]=='v') w++;
            if(map[ny][nx]=='o') s++;
            q.emplace(ny, nx);
        }
    }

    if(s > w) wolf -= w;
    else sheep -= s;
}

int main() {
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'o') sheep++;
            if(map[i][j] == 'v') wolf++;
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(!visited[i][j] && map[i][j]!='#')
                bfs(i, j);
        }
    }

    cout << sheep << " " << wolf;

    return 0;
}