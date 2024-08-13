#include <iostream>
#include <string>
using namespace std;

string map[64];

void sol(int size, int y, int x) {
    char cur = map[y][x];
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(map[i][j] != cur) {
                cout << '(';
                sol(size/2, y, x);
                sol(size/2, y, x+size/2);
                sol(size/2, y+size/2, x);
                sol(size/2, y+size/2, x+size/2);
                cout << ')';
                return;
            }
        }
    }
    cout << cur;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n;i++) {
        cin >> map[i];
    }

    sol(n, 0, 0);

    return 0;
}