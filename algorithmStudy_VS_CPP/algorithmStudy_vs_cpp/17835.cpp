#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef long long ll;

ll n, m, k;
vector<ll> target;
vector<pair<ll, ll> > road[100001];
ll dist[100001];

void dijk() {
    ll maxCost = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<> > pq;
    for(ll i : target) {
        pq.emplace(0, i);
        dist[i] = 0;
    }

    while(!pq.empty()) {
        ll cur = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i=0; i<road[cur].size(); i++) {
            ll next = road[cur][i].second;
            ll nextCost = road[cur][i].first + cost;

            if(dist[next] > nextCost) {
                pq.emplace(nextCost, next);
                dist[next] = nextCost;
            }
        }
    }

    int idx = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] != LLONG_MAX && maxCost < dist[i]) {
            idx = i;
            maxCost = dist[i];
        }
    }
    cout << idx << '\n' << maxCost;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        road[v].emplace_back(c, u);
    }
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        target.push_back(x);
    }
    for(int i=1; i<=n; i++) {
        dist[i] = LLONG_MAX;
    }
    dijk();

    return 0;
}