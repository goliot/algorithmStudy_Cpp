#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m, x;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cin >> m;

    sort(v.begin(), v.end());
    int low = 0, high = v[n-1], mid, cnt;
    while(low <= high) {
        cnt = 0;
        mid = (low + high) / 2;
        for(int i=0; i<n; i++) {
            if(v[i] > mid) {
                cnt += mid;
            }
            else {
                cnt += v[i];
            }
        }
        if(cnt <= m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << high;

    return 0;
}