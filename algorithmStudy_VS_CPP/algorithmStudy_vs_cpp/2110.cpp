#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, c, x, ans = 0;
    vector<int> v;

    cin >> n >> c;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int start = 1;
    int end = v[n-1] - v[0];
    while(start <= end) {
        int mid = (start + end) / 2;
        int cnt = 1;
        int tmp = v[0];
        for(int i=1; i<n; i++) {
            if(v[i] - tmp >= mid) {
                cnt++;
                tmp = v[i];
            }
        }

        if(cnt >= c) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << ans;

    return 0;
}