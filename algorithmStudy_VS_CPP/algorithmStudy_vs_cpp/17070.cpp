#include <iostream>
using namespace std;

int n, ans = 0;
int map[17][17];
bool visited[17][17] = {false, };
int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

void dfs(int x, int y, int dir) {
    if(x == n-1 && y == n-1) {
        ans++;
        return;
    }

    visited[x][y] = true;

    for(int i=0; i<3; i++) {
        if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
        else {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if(i < 2) {
                if(!map[nx][ny] && !visited[nx][ny]) {
                    dfs(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
            else {
                if(!map[nx][ny] && !map[nx-1][ny] && !map[nx][ny-1] && !visited[nx][ny]) {
                    dfs(nx, ny, i);
                    visited[nx][ny] = false;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    dfs(0, 1, 0);

    cout << ans;

    return 0;
}