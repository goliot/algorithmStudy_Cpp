#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n, x;
    vector<int> ropes;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        ropes.push_back(x);
    }

    sort(ropes.begin(), ropes.end());

    int res = ropes[0];
    for(int i=0; i<n; i++) {
        res = max(res, ropes[i] * (n-i));
    }
    cout << res;

    return 0;
}