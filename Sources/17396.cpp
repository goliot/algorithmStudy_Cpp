#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

ll n, m;
vector<pair<ll, ll> > v[100001];
vector<ll> vision(100001);
ll dist[100001];

void bfs(ll a) {
    fill(dist, dist + 100001, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;

    q.emplace(0, a);
    dist[a] = 0;

    while(!q.empty()) {
        ll x = q.top().second;
        ll distSum = q.top().first;
        q.pop();

        if(dist[x] < distSum) continue;
        for(int i=0; i<v[x].size(); i++) {
            ll nx = v[x][i].first;
            ll nCost = distSum + v[x][i].second;
            if(vision[nx] == 1 && nx != n-1)
                continue;
            if(dist[nx] > nCost) {
                dist[nx] = nCost;
                q.emplace(nCost, nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> vision[i];
    }
    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    bfs(0);
    if(dist[n-1] == INF) cout << -1;
    else cout << dist[n-1];

    return 0;
}