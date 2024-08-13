#include <iostream>
#include <algorithm>
#include <vector>
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
    pair<int, int> l1, l2, l3, l4;

    cin >> l1.first >> l1.second >>
        l2.first >> l2.second >>
        l3.first >> l3.second >>
        l4.first >> l4.second;

    int res = ccw(l1, l2, l3);
    res *= ccw(l1, l2, l4);
    if(res == -1) cout << 1;
    else cout << 0;

    return 0;
}