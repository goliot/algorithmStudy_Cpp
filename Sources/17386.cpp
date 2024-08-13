#include <iostream> //17386
#include <algorithm>
using namespace std;

typedef long long ll;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll x3 = p3.first, y3 = p3.second;

    ll cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross_product > 0) return 1; //반시계
    else if (cross_product < 0) return -1; //시계
    else return 0; //직선
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<ll, ll> l1[2];
    pair<ll, ll> l2[2];

    cin >> l1[0].first >> l1[0].second >> l1[1].first >> l1[1].second;
    cin >> l2[0].first >> l2[0].second >> l2[1].first >> l2[1].second;

    if(ccw(l1[0], l1[1], l2[0])*ccw(l1[0], l1[1], l2[1])<=0
    && ccw(l2[0], l2[1], l1[0])*ccw(l2[0], l2[1], l1[1])<=0) {
        cout << 1;
    } else cout << 0;

    return 0;
}