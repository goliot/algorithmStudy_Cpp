#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int n, res = INT_MAX;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[101][101] = {false, };
int map[101][101];

void find(int a, int b, int cnt) {
    queue<pair<int, int> > q;
    map[a][b] = cnt;
    q.emplace(a, b);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(map[nx][ny] == 0 || map[nx][ny] == cnt) continue;

            q.emplace(nx, ny);
            map[nx][ny] = cnt;
        }
    }
}

void bfs(int num) {
    queue<tuple<int, int, int> > q;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == num) {
                visited[i][j] = true;
                q.emplace(i, j, 0);
            }
        }
    }
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());

        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(map[nx][ny] != 0 && map[nx][ny] != num) {
                res = min(res, cnt);
                return;
            }
            if(visited[nx][ny]) continue;

            visited[nx][ny] = true;
            q.emplace(nx, ny, cnt + 1);
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

    int cnt = 2;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j] == 1) {
                find(i, j, cnt);
                cnt++;
            }
        }
    }
    for(int i=2; i<cnt; i++) {
        memset(visited, false, sizeof(visited));
        bfs(i);
    }

    cout << res;

    return 0;
}