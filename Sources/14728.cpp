#include <iostream>
#include <algorithm>
using namespace std;

int n, t; // 단원 수, 총 시간
int w[1001]; // 시간 weight
int v[1001]; // 배점 value
int dp[101][10001]; //단원, 총 시간 (idx, weight)

int main() {
    cin >> n >> t;

    for(int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=t; j++) {
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    cout << dp[n][t];
    return 0;
}