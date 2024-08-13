#include <iostream>
using namespace std;

int main() {
    int x, n, a, b;
    int s=0;

    cin >> x;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        s += a * b;
    }
    if(s == x) cout << "Yes";
    else cout << "No";

    return 0;
}