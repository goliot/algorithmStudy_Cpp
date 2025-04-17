#include <iostream> //2156
#include <algorithm>
using namespace std;

int wine[10001];
int dp[10001];
int n;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> wine[i];
    }

    dp[1] = wine[1];
    dp[2] = wine[2] + dp[1];
    dp[3] = max({dp[2], wine[2] + wine[3], wine[1]+wine[3]});
    for(int i=4; i<=n; i++) {
        dp[i] = max({dp[i-1], dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i]});
    }

    cout << dp[n];

    return 0;
}