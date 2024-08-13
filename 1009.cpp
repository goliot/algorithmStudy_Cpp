#include <iostream> //1009
using namespace std;

int main() {
    int t, a, b, val;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> a >> b;
        val = 1;
        for(int j=0; j<b; j++) {
            val = val * a % 10;
        }
        if(val == 0) cout << 10 << '\n';
        else cout << val << '\n';
    }
    return 0;
}
