#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLIS(const vector<int>& v) {
    vector<int> res;
    for(int i : v) {
        auto pos = lower_bound(res.begin(), res.end(), i);
        if(pos == res.end()) {
            res.push_back(i);
        }
        else {
            *pos = i;
        }
    }

    return (int)res.size();
}

int main() {
    int n, x;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    cout << findLIS(v);

    return 0;
}