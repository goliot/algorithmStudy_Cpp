#include <iostream> //1789
using namespace std;

typedef long long ll;

int main() {
    ll s;
    cin >> s;

    ll cnt=0, ans=0;
    for(ll i=1; i<=s; i++) {
        if(cnt+i == s) {
            ans++;
            break;
        } else if(cnt+i > s) {
            break;
        } else {
            cnt += i;
            ans++;
        }
    }

    cout << ans;

    return 0;
}