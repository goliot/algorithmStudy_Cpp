#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, res = 0;
    int map[1002] = {0, };
    int leftMax[1002] = {0, };
    int rightMax[1002] = {0, };

    cin >> n;
    for(int i=0; i<n; i++) {
        int l, h;
        cin >> l >> h;
        map[l] = h;
    }
    for(int i=1; i<=1000; i++) {
        leftMax[i] = max(leftMax[i-1], map[i]);
    }
    for(int i=1000; i>0; i--) {
        rightMax[i] = max(rightMax[i+1], map[i]);
    }

    for(int i=1; i<=1000; i++) {
        res += min(leftMax[i], rightMax[i]);
    }
    cout << res;

    return 0;
}