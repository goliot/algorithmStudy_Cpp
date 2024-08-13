#include <iostream>
#include <algorithm>
using namespace std;

int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int x1 = p1.first, y1 = p1.second;
    int x2 = p2.first, y2 = p2.second;
    int x3 = p3.first, y3 = p3.second;

    int cross_product = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (cross_product > 0) return 1;
    else if (cross_product < 0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pair<int, int> P1;
    pair<int, int> P2;
    pair<int, int> P3;
    cin >> P1.first >> P1.second;
    cin >> P2.first >> P2.second;
    cin >> P3.first >> P3.second;

    cout << ccw(P1, P2, P3);

    return 0;
}
