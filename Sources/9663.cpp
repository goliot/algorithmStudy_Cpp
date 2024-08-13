#include <iostream>
#include <cmath>
using namespace std;

int col[15];
int n, cnt = 0;

bool check(int level) {
    for(int i=0; i<level; i++) {
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
            return false;
        }
    }
    return true;
}

void queen(int x) {
    if(x == n) cnt++;
    else {
        for(int i=0; i<n; i++) {
            col[x] = i;
            if(check(x)) queen(x+1);
        }
    }
}

int main() {
    cin >> n;
    queen(0);
    cout << cnt;

    return 0;
}