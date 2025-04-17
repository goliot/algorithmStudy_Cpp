#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, a, b, c, s, t;
vector<int> dist(5001, INT_MAX);
vector<pair<int, int> > map[5001];

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.emplace(0, s);
    dist[s] = 0;
    while(!pq.empty()) {
        int now = pq.top().second;
        int nowCost = pq.top().first;
        pq.pop();

        if(nowCost > dist[now]) continue;

        if(now == t) {
            cout << nowCost;
            return;
        }

        for(auto& i : map[now]) {
            int next = i.second;
            int nextCost = nowCost + i.first;

            if(nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.emplace(nextCost, next);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        map[a].emplace_back(c, b);
        map[b].emplace_back(c, a);
    }
    cin >> s >> t;
    dijk();

    return 0;
}