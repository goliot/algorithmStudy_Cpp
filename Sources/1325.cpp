#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> map[10001];
bool visited[10001];
vector<pair<int, int> > ans;
int hacked = 1;

void dfs(int v) {
    visited[v] = true;
    for(int nv : map[v]) {
        if(!visited[nv]) {
            visited[nv] = true;
            dfs(nv);
            hacked++;
        }
    }
}

void reset() {
    for(int i=0; i<=n; i++) {
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        map[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        dfs(i);
        reset();
        ans.emplace_back(i, hacked);
        hacked = 1;
    }

    int res = -1;
    for(auto & an : ans) {
        res = max(res, an.second);
    }
    for(auto & an : ans) {
        if(an.second == res) {
            cout << an.first << " ";
        }
    }

    return 0;
}