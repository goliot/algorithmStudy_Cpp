#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1001] = {0, };
    int dp[1001] = {0, };
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int ans = dp[0];
    for(int i=1; i<n; i++) {
        if(ans < dp[i]) ans = dp[i];
    }
    cout << ans;

    return 0;
}