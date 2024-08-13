#include <iostream>
#include <queue>
using namespace std;

int a, b, n, m;
int ans=0;
bool visited[100001] = {false, };

int bfs(int dong) {
    queue<pair<int, int> > q;
    q.emplace(0, dong);
    visited[dong] = true;
    while(!q.empty()) {
        int cnt = q.front().first;
        int cur = q.front().second;
        q.pop();

        if(cur == m) return cnt;

        if(cur + 1 < 100001 && !visited[cur+1]) {
            visited[cur+1] = true;
            q.emplace(cnt+1, cur+1);
        }
        if(cur - 1 > 0 && !visited[cur-1]) {
            visited[cur-1] = true;
            q.emplace(cnt+1, cur-1);
        }
        if(cur + a < 100001 && !visited[cur+a]) {
            visited[cur+a] = true;
            q.emplace(cnt+1, cur+a);
        }
        if(cur-a > 0 && !visited[cur-a]) {
            visited[cur-a] = true;
            q.emplace(cnt+1, cur-a);
        }
        if(cur+b < 100001 && !visited[cur+b]) {
            visited[cur+b] = true;
            q.emplace(cnt+1, cur+b);
        }
        if(cur-b > 0 && !visited[cur-b]) {
            visited[cur-b] = true;
            q.emplace(cnt+1, cur-b);
        }
        if(cur*a < 100001 && !visited[cur*a]) {
            visited[cur*a] = true;
            q.emplace(cnt+1, cur*a);
        }
        if(cur*b < 100001 && !visited[cur*b]) {
            visited[cur*b] = true;
            q.emplace(cnt+1, cur*b);
        }
    }

    return -1;
}

int main() {
    cin >> a >> b >> n >> m;

    ans = bfs(n);

    cout << ans;

    return 0;
}