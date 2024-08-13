#include <iostream> //9465
#include <algorithm>
using namespace std;

int dp[2][100001];
int arr[2][100001];
int t, N;

int sol(int n) {
    for(int j=0; j<n; j++) {
        cin >> arr[0][j];
    }
    for(int j=0; j<n; j++) {
        cin >> arr[1][j];
    }
    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[0][1] = arr[0][1] + dp[1][0];
    dp[1][1] = arr[1][1] + dp[0][0];

    for(int j=2; j<n; j++) {
        dp[0][j] = arr[0][j] + max(dp[1][j-1], dp[1][j-2]);
        dp[1][j] = arr[1][j] + max(dp[0][j-1], dp[0][j-2]);
    }

    return max(dp[0][n-1], dp[1][n-1]);
}

int main() {
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> N;
        cout << sol(N) << '\n';
    }

    return 0;
}