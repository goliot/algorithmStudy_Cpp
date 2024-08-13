#include <iostream> //4181
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<int, int> > dot;

int ccw(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p3) {
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll x3 = p3.first, y3 = p3.second;

    ll cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross_product > 0) return 1; //좌회전
    else if (cross_product < 0) return -1; //우회전
    else return 0;  //직진
}

bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    int ret = ccw(dot[0], a, b);
    if(ret) return ret > 0;
    else if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
    /*int ret = ccw(dot[0], a, b);
    if(ret > 0) return true;
    else if(ret < 0) return false;
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;*/

} //반시계 방향 정렬 비교 함수

void make_first(int n) {
    for(int i=1; i<n; i++) {
        if(dot[i].second < dot[0].second
            || (dot[i].second == dot[0].second
                && dot[i].first < dot[0].first)) {
            swap(dot[0].first, dot[i].first);
            swap(dot[0].second, dot[i].second);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, x, y;
    char c;
    cin >> n;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        cin >> x >> y >> c;
        if(c == 'Y') {
            dot.emplace_back(x, y);
            cnt++;
        }
    }
    make_first(cnt);
    sort(dot.begin()+1, dot.end(), comp);

    cout << (int)dot.size() << '\n';
    for(auto & i : dot) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}