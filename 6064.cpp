#include <iostream> //6064
using namespace std;

int t, m, n, x, y;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    cin >> t;

    int max;
    while(t--) {
        int ans = -1;
        cin >> m >> n >> x >> y;
        max = lcm(m, n);
        for(int i=x; i<=max; i+=m) {
            int ny = i % n;
            if(ny == 0) ny = n;
            if(ny == y) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}