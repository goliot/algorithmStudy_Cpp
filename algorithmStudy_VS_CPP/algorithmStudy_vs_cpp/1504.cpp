#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 98765432;
int n, e;
vector<pair<int, int> > map[801];
int dist[801];

void bfs(int a) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, a);
    dist[a] = 0;

    while(!q.empty()) {
        int distSum = q.top().first;
        int x = q.top().second;
        q.pop();

        if(dist[x] < distSum)
            continue;
        for(int i=0; i<map[x].size(); i++) {
            int nx = map[x][i].first;
            int ncost = distSum + map[x][i].second;

            if(dist[nx] > ncost) {
                q.emplace(ncost, nx);
                dist[nx] = ncost;
            }
        }
    }
}

int main() {
    cin >> n >> e;
    int a, b, c;
    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        map[a].emplace_back(b, c);
        map[b].emplace_back(a, c);
    }
    int v1, v2;
    cin >> v1 >> v2;

    bfs(1);
    int to_v1 = dist[v1];
    int to_v2 = dist[v2];

    bfs(v1);
    int v1_to_v2 = dist[v2];
    int v1_to_n = dist[n];

    bfs(v2);
    int v2_to_n = dist[n];

    int res;
    res = min(INF, to_v1 + v1_to_v2 + v2_to_n);
    res = min(res, to_v2 + v1_to_v2 + v1_to_n);

    if(res >= INF) cout << -1;
    else cout << res;

    return 0;
}