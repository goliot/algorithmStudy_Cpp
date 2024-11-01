#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, c;
int map[201][201];
int city[201];

void floyd() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(map[i][k] != INT_MAX && map[k][j] != INT_MAX)
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
}

int main() {
    int a, b, t, k;
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i != j) map[i][j] = INT_MAX;
            else map[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++) {
        cin >> a >> b >> t;
        map[a][b] = t;
    }

    cin >> k;
    for(int i=1; i<=k; i++) {
        cin >> city[i];
    }
    floyd();

    int tmp = INT_MAX;
    vector<int> v;
    for(int i=1; i<=n; i++) {
        int ans = 0;
        for(int j=1; j<=k; j++) {
            if(map[i][city[j]] != INT_MAX && map[city[j]][i] != INT_MAX) {
                ans = max(map[i][city[j]] + map[city[j]][i], ans);
            }
        }
        if(tmp > ans) {
            v.clear();
            v.push_back(i);
            tmp = ans;
        }
        else if(tmp == ans) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    for(int i : v) {
        cout << i << " ";
    }

    return 0;
}