#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int map[401][401];
int v, e;

void floyd() {
    for(int k=1; k<=v; k++) {
        for(int i=1; i<=v; i++) {
            for(int j=1; j<=v; j++) {
                if (map[i][k] != INT_MAX && map[k][j] != INT_MAX)
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main() {
    int a, b, c;
    cin >> v >> e;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            if(i==j) map[i][j] = 0;
            else map[i][j] = INT_MAX;
        }
    }

    for(int i=0; i<e; i++) {
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    floyd();

    int ans = INT_MAX;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            if(i==j) continue;
            if (map[i][j] != INT_MAX && map[j][i] != INT_MAX) {
                ans = min(ans, map[i][j] + map[j][i]);
            }
        }
    }
    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}