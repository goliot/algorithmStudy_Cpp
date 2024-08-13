#include <iostream> //1780
#include <algorithm>
using namespace std;

int n;
int map[2200][2200];
int ans[3];

void sol(int x, int y, int size) {
    for(int i=x; i<x+size; i++) {
        for(int j=y; j<y+size; j++) {
            if(map[i][j] != map[x][y]) {
                sol(x, y, size/3);
                sol(x+size*1/3, y, size/3);
                sol(x+size*2/3, y, size/3);
                sol(x, y+size*1/3, size/3);
                sol(x+size*1/3, y+size*1/3, size/3);
                sol(x+size*2/3, y+size*1/3, size/3);
                sol(x, y+size*2/3, size/3);
                sol(x+size*1/3, y+size*2/3, size/3);
                sol(x+size*2/3, y+size*2/3, size/3);
                return;
            }
        }
    }
    ans[map[x][y]+1]++;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    sol(0, 0, n);

    for(int i=0; i<3; i++) {
        cout << ans[i] << '\n';
    }
}