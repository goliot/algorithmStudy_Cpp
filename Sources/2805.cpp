#include <iostream> //2805
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int start = 0;
    int end = *max_element(v.begin(), v.end());
    int res = 0;

    while(start <= end) {
        long long int total = 0;
        int mid = (start + end) / 2;
        for(int i = 0; i<n; i++) {
            if(v[i]>mid) total += v[i] - mid;
        }
        if(total < m) {
            end = mid - 1;
        }
        else {
            res = mid;
            start = mid + 1;
        }
    }
    cout << res;

    return 0;
}
