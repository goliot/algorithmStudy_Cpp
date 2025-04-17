#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m, r, t, a, b, l;
vector<pair<int, int> > map[101];
int value[101][101];
int item[101];

void dijk(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.emplace(0, start);
    value[start][start] = 0;

    while(!pq.empty()) {
        int cur = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        if(value[start][cur] < val) continue;
        value[start][cur] = val;

        for(auto & i : map[cur]) {
            int next = i.first;
            int nextVal = val + i.second;
            if(value[start][next] > nextVal) {
                pq.emplace(nextVal, next);
                value[start][next] = nextVal;
            }
        }
    }
}

int main() {
    cin >> n >> m >> r;
    for(int i=1; i<=n; i++) {
        cin >> item[i];
    }
    for(int i=0; i<r; i++) {
        cin >> a >> b >> l;
        map[a].emplace_back(b, l);
        map[b].emplace_back(a, l);
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            value[i][j] = INT_MAX;
        }
    }
    for(int i=1; i<=n; i++) {
        dijk(i);
    }

    int res = -1;
    for(int i=1; i<=n; i++) {
        int cnt = 0;
        for(int j=1; j<=n; j++) {
            if(value[i][j] <= m) {
                cnt += item[j];
            }
        }
        res = max(cnt, res);
    }
    cout << res;

    return 0;
}