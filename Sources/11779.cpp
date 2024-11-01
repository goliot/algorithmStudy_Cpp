#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, s, e;
int dist[1001];
int route[1001];
vector<pair<int, int> > v[1001];

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.emplace(0, s);
    dist[s] = 0;

    while(!pq.empty()) {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < distance) continue;
        for(int i=0; i<v[cur].size(); i++) {
            int nd = v[cur][i].second;
            int next = v[cur][i].first;

            if(distance + nd < dist[next]) {
                route[next] = cur;
                dist[next] = distance + nd;
                pq.emplace(dist[next], next);
            }
        }
    }
}

int main() {
    vector<int> ans;

    cin >> n >> m;
    int a, b, c;
    for(int i=1; i<=n; i++) {
        dist[i] = INT_MAX;
    }
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }
    cin >> s >> e;

    dijk();

    route[s] = 0;
    int idx = e;

    while(true) {
        if(route[idx] == 0) {
            ans.push_back(s);
            break;
        }
        ans.push_back(idx);
        idx = route[idx];
    }
    reverse(ans.begin(), ans.end());

    cout << dist[e] << '\n';
    cout << ans.size() << '\n';
    for(int i : ans)
        cout << i << " ";

    return 0;
}