#include <iostream> //9251
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
    cin >> s1;
    cin >> s2;

    for(int i=0; i<s1.length(); i++) {
        dp[0][i] = 0;
    }
    for(int i=0; i<s2.length(); i++) {
        dp[i][0] = 0;
    }

    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout << dp[s1.length()][s2.length()];

    return 0;
}