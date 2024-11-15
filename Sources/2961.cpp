#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
ll res = LONG_LONG_MAX;
pair<ll, ll> map[11];

void dfs(int idx, ll s, ll b) {
    if(idx == n) {
        if(b != 0)
            res = min(res, abs(s - b));
        return;
    }
    dfs(idx + 1, s, b);
    dfs(idx + 1, s * map[idx].first, b + map[idx].second);
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> map[i].first >> map[i].second;
    }
    dfs(0, 1, 0);

    cout << res;

    return 0;
}