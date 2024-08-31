#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x, ans = 0;
    vector<int> arr;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++) {
        int goal = arr[i];
        int left = 0, right = n - 1;
        if(left == i) left++;
        if(right == i) right--;
        while(left < right) {
            int tmp = arr[left] + arr[right];
            if(tmp == goal) {
                ans++;
                break;
            }
            else if(tmp < goal) {
                left++;
                if(left == i) left++;
            }
            else {
                right--;
                if(right == i) right--;
            }
        }
    }
    cout << ans;

    return 0;
}