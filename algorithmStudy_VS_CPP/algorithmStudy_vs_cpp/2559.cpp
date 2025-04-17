#include <iostream> //2559
#include <algorithm>
#include <climits>
using namespace std;

int arr[100001] = {0, };
int pre[100001] = {0, };
int pre_k[100001] = {0, };
int n, k, ans = INT_MIN;

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++) {
        pre[i] = pre[i-1] + arr[i];
    }
    for(int i=1; i<=n-k+1; i++) {
        pre_k[i] = pre[i+k-1] - pre[i-1];
    }
    for(int i=1; i<=n-k+1; i++) {
        ans = max(ans, pre_k[i]);
    }
    cout << ans;

    return 0;
}