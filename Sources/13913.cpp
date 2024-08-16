#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k, ans = 0;
int dist[100001] = {0, };
int lastPos[100001] = {0, };
bool visited[100001] = {false, };
vector<int> path;

void bfs() {
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()) {
        int x = q.front();
        int dx[3] = {x - 1, x + 1, x * 2};
        q.pop();
        for(int i=0; i<3; i++) {
            int nx = dx[i];
            if (nx < 0 || nx > 100000 || visited[nx])
                continue;

            q.push(nx);
            visited[nx] = true;
            dist[nx] = dist[x] + 1;
            lastPos[nx] = x;
            if(nx == k) {
                ans = dist[nx];
                return;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    if(n == k) {
        cout << 0 << endl << n;
    }
    else {
        bfs();
        cout << ans << endl;
        path.push_back(k);
        for(int i=0; i<ans; i++) {
            path.push_back(lastPos[k]);
            k = lastPos[k];
        }
        for(int i=path.size() - 1; i>=0; i--) {
            cout << path[i] << ' ';
        }
    }

    return 0;
}