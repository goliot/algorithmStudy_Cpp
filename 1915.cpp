#include <iostream> //1915
#include <algorithm>
using namespace std;

int map[1001][1001] = {0, };
int dp[1001][1001] = {0, };
int n, m, ans = 0;

int main() {
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++) {
            map[i][j+1] = s[j] - '0';
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(map[i][j] == 0) dp[i][j] = 0;
            else {
                if(i==1 || j==1) dp[i][j] = 1;
                else dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans * ans;

    return 0;
}