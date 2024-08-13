#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int dy[] = { 0,0,-1,1,-1,-1,1,1 };
int dx[] = { 1,-1,0,0,-1,1,-1,1 };

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.emplace(y, x);
    visited[y][x] = true;
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx<0 || nx>=w || ny<0 || ny>=h) {
                continue;
            }
            if(map[ny][nx] == 1 && !visited[ny][nx]) {
                q.emplace(ny, nx);
                visited[ny][nx] = true;
            }
        }
    }
}

int main() {
    while(true) {
        int cnt = 0;
        cin >> w >> h;
        if(w==0 && h==0) break;

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> map[i][j];
            }
        }

        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(!visited[i][j] && map[i][j]==1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}