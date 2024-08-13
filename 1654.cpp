#include <iostream> //1654
#include <algorithm>
using namespace std;

int arr[10001];

int main() {
    int k, n, ans;
    cin >> k >> n;

    int maxi = 0;

    for(int i=0; i<k; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    long long mid, high, low;

    low = 1;
    high = maxi;
    ans = 0;

    while(low <= high) {
        mid = (low+high) / 2;
        int cnt = 0;
        for(int i=0; i<k; i++) {
            cnt += arr[i] / mid;
        }
        if(cnt >= n) {
            low = mid + 1;
            if(ans < mid) ans = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans;

    return 0;
}