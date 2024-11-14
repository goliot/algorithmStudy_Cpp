#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, a, b;
vector<int> graph[2001];
bool visited[2001];
bool res;

void dfs(int node, int cnt) {
    if(cnt == 4) {
        res = true;
        return;
    }
    visited[node] = true;
    for(int next : graph[node]) {
        if(!visited[next]) {
            dfs(next, cnt + 1);
            visited[next] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, 0);
            visited[i] = false;
        }
        if(res) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}