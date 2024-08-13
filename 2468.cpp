#include <iostream> //2468
#include <cstring>
using namespace std;

int n;
int map[101][101];
bool visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x, int height) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(visited[ny][nx]) continue;
        if(map[ny][nx] <= height) continue;

        visited[ny][nx] = true;
        dfs(ny, nx, height);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    int maxCnt = 1;
    for(int height=1; height<=100; height++) {
        int heightCount = 0;
        memset(visited, false, sizeof(visited));
        for(int y=0; y<n; y++) {
            for(int x=0; x<n; x++) {
                if(!visited[y][x] && map[y][x] > height) {
                    visited[y][x] = true;
                    dfs(y, x, height);
                    heightCount++;
                }
            }
        }
        if(heightCount==0) break;
        if(heightCount > maxCnt) maxCnt = heightCount;
    }

    cout << maxCnt;

    return 0;
}