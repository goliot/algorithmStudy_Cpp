#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLIS(const vector<int>& A) {
    int n = A.size();
    vector<int> dp, parent(n, -1);

    for (int i = 0; i < n; ++i) {
        auto pos = lower_bound(dp.begin(), dp.end(), A[i], [&](int idx, int val) {
            return A[idx] < val;
        });

        int index = pos - dp.begin();
        if (pos == dp.end()) {
            dp.push_back(i);
        } else {
            dp[index] = i;
        }

        // parent 배열을 갱신하여 LIS 재구성에 활용
        if (index > 0) {
            parent[i] = dp[index - 1];
        }
    }

    // LIS 재구성
    vector<int> lis;
    for (int i = dp.back(); i >= 0; i = parent[i]) {
        lis.push_back(A[i]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    int n, x;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    vector<int> lis = findLIS(v);
    cout << lis.size() << '\n';
    for(int i : lis) {
        cout << i << " ";
    }

    return 0;
}
