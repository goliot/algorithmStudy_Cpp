#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int t, n, d, c, a, b, s;
int dp[10001];

void dijk(vector<pair<int, int> > v[]) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    dp[c] = 0;
    pq.emplace(0, c);
    while(!pq.empty()) {
        int cur = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        if(dp[cur] < curCost) continue;

        for(auto& i : v[cur]) {
            int next = i.second;
            int nextCost = curCost + i.first;
            if(nextCost < dp[next]) {
                dp[next] = nextCost;
                pq.emplace(nextCost, next);
            }
        }
    }

    int cnt = 0, ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i] != INT_MAX) {
            cnt++;
            ans = max(ans, dp[i]);
        }
    }
    cout << cnt << ' ' << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while(t--) {
        vector<pair<int, int> > v[10001];
        cin >> n >> d >> c;
        for(int i=0; i<d; i++) {
            cin >> a >> b >> s;
            v[b].emplace_back(s, a);
        }
        fill(dp, dp+10001, INT_MAX);
        dijk(v);
    }

    return 0;
}