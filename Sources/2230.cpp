#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    vector<int> arr;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int s = 0, e = 0;
    int res = INT_MAX;
    while(s < arr.size() && e < arr.size() && s <= e) {
        if(arr[e] - arr[s] < m) {
            e++;
        }
        else {
            res = min(res, arr[e] - arr[s]);
            s++;
        }
    }

    cout << res;
}