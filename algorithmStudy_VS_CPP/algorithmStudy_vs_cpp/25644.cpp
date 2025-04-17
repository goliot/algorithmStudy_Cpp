#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001] = {0, };
int n, res = 0, maxN=0;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=n-1; i>=0; i--) {
        maxN = max(maxN, arr[i]);
        res = max(res, maxN - arr[i]);
    }

    cout << res;

    return 0;
}