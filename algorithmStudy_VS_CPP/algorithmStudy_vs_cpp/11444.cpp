#include <iostream>
#include <map>
using namespace std;
#define DIV	1000000007LL
typedef long long ll;

map<ll, ll> f;

ll fib(ll n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 1;
    if(f.count(n) > 0) return f[n];

    if(n%2==0) {
        ll m = n/2;
        ll tmp1 = fib(m-1);
        ll tmp2 = fib(m);
        f[n] = ((2LL * tmp1 + tmp2) * tmp2) % DIV;
        return f[n];
    }
    ll m = (n+1) / 2;
    ll tmp1 = fib(m);
    ll tmp2 = fib(m-1);
    f[n] = (tmp1 * tmp1 + tmp2 * tmp2) % DIV;
    return f[n];
}

int main() {
    ll n;
    cin >> n;
    cout << fib(n);

    return 0;
}