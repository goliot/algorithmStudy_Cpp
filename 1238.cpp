#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define INF 98765432
#define pii pair<int, int>
using namespace std;

int n, m, x;
vector<pii> v[1001];
int dst[1001];
int res;

void dijk(int a, int d) {
    memset(dst, INF, sizeof(dst));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, a);
    dst[a] = 0;
    while(!pq.empty()) {
        int cx = pq.top().second;
        int cdst = pq.top().first;
        pq.pop();
        if(cx==d) {
            res = dst[cx];
            break;
        }
        for(int i=0; i<v[cx].size(); i++) {
            int nx = v[cx][i].first;
            int ndst = v[cx][i].second + cdst;
            if(dst[nx] > ndst) {
                dst[nx] = ndst;
                pq.emplace(ndst, nx);
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;
    int ans1, ans2, ans;
    ans = 0;
    int a, b, t;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        v[a].emplace_back(b, t);
    }
    for(int i=1; i<=n; i++) {
        dijk(i, x);
        ans1 = res;
        dijk(x, i);
        ans2 = res;
        if(ans < ans1+ans2)
            ans = ans1+ans2;
    }
    cout << ans;

    return 0;
}