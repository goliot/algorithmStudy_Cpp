#include <iostream>
#include <vector>
using namespace std;

int n, res = 0;
vector<vector<int> > v;

void dfs(int x) {
    if(x >= n) {
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(v[i][0] <= 0) cnt++;
        }
        if(cnt > res) res = cnt;
        return;
    }

    if(v[x][0] <= 0) dfs(x + 1);
    else {
        bool check = false;
        for(int i=0; i<n; i++) {
            if(x == i || v[i][0] <= 0) continue;

            v[i][0] -= v[x][1];
            v[x][0] -= v[i][1];
            check = true;
            dfs(x + 1);
            v[i][0] += v[x][1];
            v[x][0] += v[i][1];
        }

        if(!check) dfs(n);
    }
}

int main() {
    cin >> n;
    v.resize(n, vector<int>(2));
    for(int i=0; i<n; i++) {
        int s, w;
        cin >> s >> w;
        v[i][0] = s;
        v[i][1] = w;
    }

    dfs(0);
    cout << res;
    return 0;
}