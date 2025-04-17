#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> arr;
    unordered_set<int> sumSet;

    int n, x;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr.size(); j++) {
            sumSet.insert(arr[i] + arr[j]);
        }
    }
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j>=0; j--) {
            if(sumSet.find(arr[i] - arr[j]) != sumSet.end()) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}