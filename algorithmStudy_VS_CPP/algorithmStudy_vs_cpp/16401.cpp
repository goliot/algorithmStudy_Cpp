#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int m, n;
    vector<int> v;
    cin >> m >> n;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int low = 1, high = v[n-1], mid = 0, cnt = 0, res = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        cnt = 0;
        for(int i=0; i<n; i++) {
            cnt += v[i] / mid;
        }
        if(cnt < m) {
            high = mid - 1;
        }
        else {
            res = mid;
            low = mid + 1;
        }
    }

    cout << res;
    return 0;
}