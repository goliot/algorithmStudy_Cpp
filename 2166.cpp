#include <iostream> //2166
#include <vector>
#include <cmath>
using namespace std;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
    double res = x1*y2 + x2*y3 + x3*y1;
    res += (-y1*x2 - y2*x3 - y3*x1);
    return res/2;
}

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    double res = 0;
    for(int i=1; i<n; i++) {
        res += ccw(v[0].first, v[0].second, v[i-1].first, v[i-1].second, v[i].first, v[i].second);
    }

    printf("%.1f", abs(res));

    return 0;
}