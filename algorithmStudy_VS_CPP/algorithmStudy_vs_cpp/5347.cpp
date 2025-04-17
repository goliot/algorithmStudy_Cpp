#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll sol(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ll a, b, t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << sol(a, b) << '\n';
    }

    return 0;
}
