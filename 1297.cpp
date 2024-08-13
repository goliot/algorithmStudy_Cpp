#include <iostream> //1297
#include <cmath>
using namespace std;

int main() {
    int d, h, w;

    cin >> d >> h >> w;

    double x = sqrt(d*d / double(h*h + w*w));
    cout << int(x*h) << " " << int(x*w);

    return 0;
}