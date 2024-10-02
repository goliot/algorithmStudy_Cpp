#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
int dx[2];
int visited[1000001] = {0, };

void bfs() {
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            if (nx > f || nx <= 0) continue;
            if (visited[nx] != 0) continue;

            q.push(nx);
            visited[nx] = visited[x] + 1;
        }
    }
}

int main() {
    cin >> f >> s >> g >> u >> d;
    dx[0] = u;
    dx[1] = -d;

    bfs();
    if(visited[g] != 0) cout << visited[g] - 1;
    else cout << "use the stairs";

    return 0;
}