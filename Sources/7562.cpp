#include <iostream>
#include <queue>
using namespace std;

int t, n;
int curX, curY, tarX, tarY;
int arr[301][301];
bool visited[301][301];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<pair<int, int> > q;

void bfs(int a, int b) {
    q.emplace(a, b);
    visited[a][b] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==tarX && y==tarY) {
            cout << arr[x][y] << '\n';
            while(!q.empty()) {
                q.pop();
            }
            return;
        }
        for(int i=0; i<8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx && 0<=ny && nx<n && ny<n && !visited[nx][ny]) {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
                arr[nx][ny] = arr[x][y] + 1;
            }
        }
    }
}

void reset() {
    while(!q.empty()) q.pop();
    for(int i=0; i<301; i++) {
        for(int j=0; j<301; j++) {
            visited[i][j] = false;
            arr[i][j] = 0;
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> curX >> curY;
        cin >> tarX >> tarY;
        bfs(curX, curY);
        reset();
    }

    return 0;
}