#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    unordered_map<ll, int> m;
    ll x;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        m[x]++;
    }
    int tmp = 0;
    ll ans = 0;
    for(auto it : m) {
        if(it.second > tmp) {
            tmp = it.second;
            ans = it.first;
        }
        else if(it.second == tmp) {
            ans = min(ans, it.first);
        }
    }

    cout << ans;
    return 0;
}