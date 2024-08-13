#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int n, m, dist[1001];
vector<pair<int, int> > graph[1001];

int bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(auto next : graph[x]) {
            if(dist[next.first] >= 0) continue;
            dist[next.first] = dist[x] + next.second;
            q.push(next.first);
        }
    }

    return dist[end];
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n-1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].emplace_back(v, cost);
        graph[v].emplace_back(u, cost);
    }

    while(m--) {
        int start, end;
        cin >> start >> end;
        memset(dist, -1, sizeof(dist));
        cout << bfs(start, end) << '\n';
    }

    return 0;
}