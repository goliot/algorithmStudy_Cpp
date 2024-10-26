#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll t, k, n;
    cin >> t;

    while(t--) {
        priority_queue<ll, vector<ll>, greater<> > q;

        cin >> k;
        for(int i=0; i<k; i++) {
            cin >> n;
            q.push(n);
        }
        ll res = 0;
        while(q.size() > 1) {
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            res += (a + b);
            q.push(a + b);
        }
        cout << res << '\n';
    }

    return 0;
}