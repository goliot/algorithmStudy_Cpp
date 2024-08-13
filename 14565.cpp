#include <iostream> //14565
using namespace std;
typedef long long ll;

ll xGCD(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = xGCD(b, a%b, x, y);
    ll tmp = y;
    y = x - (a/b)*y;
    x = tmp;

    if(x <= 0) {
        x += b;
        y -= a;
    }

    return gcd;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, a;
    cin >> n >> a;
    ll c, k;
    ll g = xGCD(a, n, c, k);
    if(g != 1) cout << n-a << ' ' << -1;
    else cout << n-a << ' ' << c;

    return 0;
}
