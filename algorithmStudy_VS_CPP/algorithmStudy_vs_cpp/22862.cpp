#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, x;
    vector<int> v;
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int res = 0;
    int cnt = 0;
    int len = 0;
    int s = 0, e = 0;
    while(e < n) {
        if(v[e] % 2 == 0) {
            len++;
            e++;
            res = max(res, len - cnt);
        }
        else {
            if (cnt + 1 <= k) {
                cnt++;
                len++;
                res = max(res, len - cnt);
                e++;
            } else {
                if (e > s) {
                    if (v[s] % 2 == 1) cnt--;
                    s++;
                    len--;
                } else {
                    s++;
                    e++;
                }
            }
        }
    }
    cout << res;

    return 0;
}