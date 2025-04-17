#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

pair<int, int> conv[101];
bool visited[101] = {false, };
pair<int, int> home;
pair<int, int> fest;

void bfs(int n) {
    queue<pair<int, int> > q;
    q.push(home);
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(abs(fest.first - x) + abs(fest.second - y) <= 1000) {
            cout << "happy" << '\n';
            return;
        }
        for(int i=0; i<n; i++) {
            if(visited[i]) {
                continue;
            }
            if(abs(conv[i].first - x) + abs(conv[i].second - y) <= 1000) {
                visited[i] = true;
                q.push(conv[i]);
            }
        }
    }
    cout << "sad" << '\n';
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> home.first >> home.second;
        for (int i = 0; i < n; i++) {
            cin >> conv[i].first >> conv[i].second;
        }
        cin >> fest.first >> fest.second;
        bfs(n);
        fill(visited, visited+101, false);
    }

    return 0;
}