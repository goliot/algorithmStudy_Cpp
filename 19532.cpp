#include <iostream> //19532
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    for(int i=-999; i<=999; i++) {
        x = i;
        for(int j=-999; j<=999; j++) {
            y = j;
            if(a*x+b*y==c && d*x+e*y==f) {
                cout << x << " " << y;
                return 0;
            }
        }
    }

    return 0;
}
