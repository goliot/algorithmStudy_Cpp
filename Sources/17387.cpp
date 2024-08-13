#include <iostream> //17386
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll x3 = p3.first, y3 = p3.second;

    ll cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross_product > 0) return 1; //반시계
    else if (cross_product < 0) return -1; //시계
    else return 0; //직선
}

bool sol(pair<pll, pll> l1, pair<pll, pll> l2) {
    pll p1 = l1.first;
    pll p2 = l1.second;
    pll p3 = l2.first;
    pll p4 = l2.second;

    int case1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int case2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if(case1==0 && case2==0) {
        if(p1 > p2) swap(p2, p1);
        if(p3 > p4) swap(p3, p4);

        return p3<=p2 && p1<=p4;
    }
    return case1<=0 && case2<=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<pll, pll> l1;
    pair<pll, pll> l2;

    cin >> l1.first.first >> l1.first.second >> l1.second.first >> l1.second.second;
    cin >> l2.first.first >> l2.first.second >> l2.second.first >> l2.second.second;

    if(sol(l1, l2)) cout << 1;
    else cout << 0;

    return 0;
}