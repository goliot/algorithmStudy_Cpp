#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, m;
    cin >> t;
    while(t--) {
        int x, res = 0;
        vector<int> A;
        vector<int> B;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >> x;
            A.push_back(x);
        }
        for(int i=0; i<m; i++) {
            cin >> x;
            B.push_back(x);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int idx = 0;
        for(int i=0; i<n; i++) {
            while(idx < m && A[i] > B[idx])
                idx++;
            res += idx;
        }

        cout << res << '\n';
    }
}