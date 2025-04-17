#include <iostream> //9655
#include <algorithm>
using namespace std;

int n;
int dp[1001];

int main() {
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++) {
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);
    }
    if(dp[n] % 2 == 1) cout << "SK";
    else cout << "CY";

    return 0;
}
