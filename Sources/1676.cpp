#include <iostream> //1676
using namespace std;

int sol(int n) {
    if(n < 5) return 0;
    else {
        int cnt = 0;
        for(int i=5; n/i >= 1; i *= 5) {
            cnt += n/i;
        }
        return cnt;
    }
}

int main() {
    int n;
    cin >> n;
    cout << sol(n);

    return 0;
}