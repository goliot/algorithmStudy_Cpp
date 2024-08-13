#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int h, w, res = 0;
    cin >> h >> w;

    int arr[502] = {0, };
    int leftMax[502] = {0, };
    int rightMax[502] = {0, };
    for(int i=0; i<w; i++) {
        cin >> arr[i];
    }
    leftMax[0] = arr[0];
    for(int i=1; i<w; i++) {
        leftMax[i] = max(leftMax[i-1], arr[i]);
    }
    for(int i=w; i>0; i--) {
        rightMax[i] = max(rightMax[i+1], arr[i]);
    }

    for(int i=0; i<500; i++) {
        res += max(0, min(rightMax[i], leftMax[i]) - arr[i]);
    }
    cout << res;

    return 0;
}