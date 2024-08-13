#include <iostream>
#include <queue>
using namespace std;

int n, a, b, m;
int map[101][101];
int visited[101];
queue<int> q;

void bfs(int k) {
    q.push(k);
    while(!q.empty()) {
        k = q.front();
        q.pop();
        for(int i=1; i<=n; i++) {
            if(map[k][i]!=0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[k]+1;
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> a >> b;
    cin >> m;

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }

    bfs(a);
    if(visited[b] == 0) visited[b] = -1;
    cout << visited[b];

    return 0;
}