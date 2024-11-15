#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll minRes = LLONG_MAX, maxRes = LLONG_MIN;
int op[4];
int arr[101];

void dfs(ll res, int idx) {
    if(idx == n) {
        minRes = min(res, minRes);
        maxRes = max(res, maxRes);
        return;
    }
    for(int i=0; i<4; i++) {
        if(op[i] > 0) {
            op[i]--;
            if(i==0)
                dfs(res + arr[idx], idx + 1);
            else if(i==1)
                dfs(res - arr[idx], idx + 1);
            else if(i==2)
                dfs(res * arr[idx], idx + 1);
            else
                dfs(res / arr[idx], idx + 1);
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<4; i++) {
        cin >> op[i];
    }

    dfs(arr[0], 1);
    cout << maxRes << '\n' << minRes;

    return 0;
}