#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > tree[10001];
int res = 0;
int visited[10001] = {-1, };

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<tree[x].size(); i++) {
            if(visited[tree[x][i].first]==-1) {
                visited[tree[x][i].first] = visited[x] + tree[x][i].second;
                q.push(tree[x][i].first);

                res = max(res, visited[tree[x][i].first]);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    for(int i=1; i<=n; i++) {
        memset(visited, -1, sizeof(visited));
        bfs(i);
    }

    cout << res;

    return 0;
}