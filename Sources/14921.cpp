#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, x;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    if(n == 2) {
        cout << v[0] + v[1];
        return 0;
    }

    int left = 0, right = n-1, ans = v[left] + v[right], tmp = abs(v[left] + v[right]);
    while(left < right) {
        int val = v[left] + v[right];
        if(abs(val) < tmp) {
            tmp = abs(val);
            ans = val;
        }
        if(val < 0)
            left++;
        else
            right--;
    }

    cout << ans;
    return 0;
}