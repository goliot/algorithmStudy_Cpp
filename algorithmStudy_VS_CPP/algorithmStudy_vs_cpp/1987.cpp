#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m, res = INT_MIN;
char map[21][21];
bool visited[26] = {false, };

void dfs(int x, int y, int cnt) {
    res = max(res, cnt);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[map[nx][ny] - 'A']) continue;

        visited[map[nx][ny] - 'A'] = true;
        dfs(nx, ny, cnt + 1);
        visited[map[nx][ny] - 'A'] = false;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    visited[map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << res;
    return 0;
}