#include <iostream>
#include <queue>
using namespace std;

int n, k;
bool visited[100001];

int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    q.push({0, n});
    visited[n] = true;
    while(!q.empty()) {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if(x == k) return time;
        if(x*2 < 100001 && !visited[x*2]) {
            q.push({time, x*2});
            visited[x*2] = true;
        }
        if(x+1<100001 && !visited[x+1]) {
            q.push({time+1, x+1});
            visited[x+1] = true;
        }
        if(x-1>=0 && !visited[x-1]) {
            q.push({time+1, x-1});
            visited[x-1] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    cout << bfs();

    return 0;
}
