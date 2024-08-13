#include <iostream> //2178
#include <queue>
using namespace std;

int n, m;
int maze[101][101];
int visited[101][101];
int dist[101][101];

queue<pair<int, int> > q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y) {
    visited[x][y] = 1;
    q.emplace(x, y);
    dist[x][y]++;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if((0<=nx && nx<n) && (0<=ny && ny<m) && !visited[nx][ny] && maze[nx][ny]==1) {
                visited[nx][ny] = 1;
                q.emplace(nx, ny);
                dist[nx][ny] = dist[a][b] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<m; j++) {
            maze[i][j] = s[j] - '0';
        }
    }
    bfs(0, 0);

    cout << dist[n-1][m-1];

    return 0;
}