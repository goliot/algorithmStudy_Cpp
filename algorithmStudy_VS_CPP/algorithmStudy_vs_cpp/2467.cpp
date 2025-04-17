#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int n, x;
    vector<long long> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int left = 0, right = n-1;
    long long ansL = v[left], ansR = v[right];
    long long tmp = abs(v[left] + v[right]);
    while(left < right) {
        long long val = v[left] + v[right];
        if(abs(val) <= tmp) {
            tmp = abs(val);
            ansL = v[left];
            ansR = v[right];
        }
        if(val < 0)
            left++;
        else
            right--;
    }
    cout << ansL << ' ' << ansR;

    return 0;
}