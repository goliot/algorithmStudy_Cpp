#include <iostream> //9461
using namespace std;

long long dp[101];
int t, n;

int main() {
    cin >> t;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for(int i=4; i<=100; i++) {
        dp[i] = dp[i-3] + dp[i-2];
    }

    for(int i = 0; i<t; i++) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}