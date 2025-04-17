#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

typedef long long ll;

vector<ll> primeNumber(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<ll> primes;
    for(ll i = 2; i <= limit; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

ll sol(ll a, ll b) {
    ll sqrt_b = (ll)sqrt(b);
    vector<ll> primes = primeNumber(sqrt_b);
    set<ll> almost_primes;
    for(ll prime : primes) {
        ll tmp = prime * prime;
        while(tmp <= b) {
            if(tmp >= a) {
                almost_primes.insert(tmp);
            }
            if(tmp > b / prime) break;
            tmp *= prime;
        }
    }

    return (ll)almost_primes.size();
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << sol(a, b);
    return 0;
}