#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, res = INT_MAX;
int map[11][11];
bool visited[11] = {false, };

void dfs(int start, int cur, int cnt, int cost) {
    if(cnt == n && map[cur][start] != 0) {
        res = min(res, cost + map[cur][start]);
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visited[i] && map[cur][i] != 0) {
            visited[i] = true;
            dfs(start, i, cnt + 1, cost + map[cur][i]);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        visited[i] = true;
        dfs(i, i, 1, 0);
        visited[i] = false;
    }
    cout << res;

    return 0;
}