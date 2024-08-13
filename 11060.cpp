#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int dp[1001];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp[i] = 987654321;
    }
    dp[1] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=arr[i]; j++) {
            if(i+j <= n)
                dp[i+j]=min(dp[i]+1, dp[i+j]);
        }
    }
    if(dp[n]==987654321) cout << -1;
    else cout << dp[n];

    return 0;
}