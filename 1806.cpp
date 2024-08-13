#include <iostream> //1806
#include <climits>
#include <algorithm>
using namespace std;

int n, s;
int ans = INT_MAX;
int arr[100001] = {0, };
int pre[100001] = {0, };

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1] + arr[i];
    }
    int start = 1, end = 1;
    for(int i=1; i<=n; i++) {
        while(start<=n && end<=n) {
            if(pre[end] - pre[start-1] >= s){
                ans = min(ans, end-start+1);
                start++;
            }
            else end++;
        }
    }
    if(ans == INT_MAX) cout << 0;
    else cout << ans;


    return 0;
}
