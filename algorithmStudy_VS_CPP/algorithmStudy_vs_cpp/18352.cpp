#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int n, m, k, x;
int d[300001];
vector<int> v[300001];

void dijkstra(int s) {
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++) {
            int next = v[cur][i];
            if(d[next] > d[cur] + 1) {
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k >> x;
    for(int i=1; i<=n; i++) {
        d[i] = INT_MAX;
    }
    for(int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
    }
    dijkstra(x);
    bool check = false;
    for(int i=1; i<=n; i++) {
        if(d[i]==k) {
            check = true;
            cout << i << '\n';
        }
    }
    if(!check) cout << "-1";

    return 0;
}