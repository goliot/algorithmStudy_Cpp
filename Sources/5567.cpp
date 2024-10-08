#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m, ans = 0;
int visited[501] = {0, };
vector<vector<int> > v(501);

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int next : v[x]) {
            if(visited[next] || visited[x] > 2) continue;
            q.push(next);
            visited[next] = visited[x] + 1;
            ans++;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    cout << ans;

    return 0;
}