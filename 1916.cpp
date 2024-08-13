#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
#define INF 987654321

int n, m;
vector<pair<int, int> > bus[MAX];
int start, dest;
int dist[MAX];

void dijk() {
    priority_queue<pair<int, int> > pq;
    pq.emplace(0, start);
    dist[start] = 0;
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(auto & i : bus[cur]) {
            int next = i.first;
            int ncost = cost + i.second;
            if(dist[next]>ncost) {
                dist[next] = ncost;
                pq.emplace(-ncost, next);
            }
        }
    }
    cout << dist[dest];
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].emplace_back(b, c);
    }
    cin >> start >> dest;
    for(int i=1; i<=n; i++) {
        dist[i] = INF;
    }

    dijk();

    return 0;
}