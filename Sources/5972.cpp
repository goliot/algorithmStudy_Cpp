#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 98765432;
vector<pair<int, int> > v[50001];
int dist[50001];

void bfs(int a) {
    fill(dist, dist + 50001, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, a);
    dist[a] = 0;

    while(!q.empty()) {
        int x = q.top().second;
        int distSum = q.top().first;
        q.pop();

        if(dist[x] < distSum) continue;

        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i].first;
            int nCost = distSum + v[x][i].second;

            if(dist[nx] > nCost) {
                q.emplace(nCost, nx);
                dist[nx] = nCost;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }

    bfs(1);
    cout << dist[n];

    return 0;
}