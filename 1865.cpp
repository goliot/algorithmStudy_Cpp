#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 30'000'000

int n, m, w;

struct edge {
    int s, e, t;
};

bool bf(int x, const vector<edge>& edges) {
    vector<int> dist(x+1, MAX);
    int s, e, t;
    dist[1] = 0;
    for(int i=1; i<x; i++) {
        for(auto edge : edges) {
            s = edge.s;
            e = edge.e;
            t = edge.t;
            dist[e] = min(dist[e], dist[s] + t);
        }
    }
    for(auto edge : edges) {
        s = edge.s;
        e = edge.e;
        t = edge.t;
        if(dist[e] > dist[s] + t) {
            return true;
        }
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;

    int s = s, e, t;
    while(tc > 0) {
        cin >> n >> m >> w;
        vector<edge> edges;

        for(int i=0; i<m; i++) {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int i=0; i<w; i++) {
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        if(bf(n,edges)) cout << "YES\n";
        else cout << "NO\n";
        tc--;
    }

    return 0;
}