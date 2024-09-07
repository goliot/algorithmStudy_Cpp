#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k, ans = 0;
    int arr[100001] = {0, };
    cin >> n >> k;
    vector<int> v(n, 0);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    int s = 0, e = 0;
    for(s = 0; s<n; s++) {
        while(e < n && arr[v[e]] < k) {
            arr[v[e]]++;
            e++;
        }
        ans = max(ans, e - s);
        if(e == n) break;
        arr[v[s]]--;
    }
    cout << ans;

    return 0;
}