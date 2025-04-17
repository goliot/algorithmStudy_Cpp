#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int map[16][16];
int dp[1 << 16][16];

int dfs(int mask, int cur) {
    if(mask == (1 << n) - 1) {
        return map[cur][0] == 0 ? INT_MAX : map[cur][0];
    }
    if(dp[mask][cur] != -1) {
        return dp[mask][cur];
    }
    int res = INT_MAX;
    for(int next = 0; next < n; next++) {
        if(!(mask & (1 << next)) && map[cur][next] != 0) {
            res = min(res, dfs(mask | (1 << next), next) + map[cur][next]);
        }
    }
    return dp[mask][cur] = res;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }
    fill(&dp[0][0], &dp[(1 << n) - 1][n-1] + 1, -1);
    int res = dfs(1, 0);
    cout << res;
    return 0;
}