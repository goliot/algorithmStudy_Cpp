#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    long long cnt = 0;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int tmp = v[i] + v[j];
            int a = lower_bound(v.begin() + j + 1, v.end(), -tmp) - v.begin();
            int b = upper_bound(v.begin() + j + 1, v.end(), -tmp) - v.begin();
            cnt += b - a;
        }
    }

    cout << cnt;
    return 0;
}