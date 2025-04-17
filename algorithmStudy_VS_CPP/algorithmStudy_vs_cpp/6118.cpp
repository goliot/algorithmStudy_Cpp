#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int dist[20001];
bool visited[20001] = {false, };
vector<int> map[20001];

void bfs() {
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto& next : map[cur]) {
            if(!visited[next]) {
                q.push(next);
                dist[next] = dist[cur] + 1;
                visited[next] = true;
            }
        }
    }

    int maxDist=0, res=0, cnt=0;
    bool flag = false;
    for(int i=1; i<=n; i++) {
        maxDist = max(maxDist, dist[i]);
    }

    for(int i=1; i<=n; i++) {
        if(maxDist == dist[i]) {
            if(!flag) {
                flag = true;
                res = i;
            }
            cnt++;
        }
    }

    cout << res << " " << maxDist << " " << cnt;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    bfs();

    return 0;
}