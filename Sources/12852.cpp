#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n;
int res = INT_MAX;
vector<int> v, ret;

void dfs(int cnt, int cur) {
    if(cnt > res) return;
    if(cur == 1) {
        if(cnt < res) {
            res = cnt;
            v.push_back(cur);
            ret = v;
            v.pop_back();
        }
        return;
    }
    v.push_back(cur);

    if(cur % 3 == 0) {
        dfs(cnt + 1, cur / 3);
    }
    if(cur % 2 == 0) {
        dfs(cnt + 1, cur / 2);
    }
    dfs(cnt + 1, cur - 1);

    v.pop_back();
}

int main() {
    cin >> n;
    dfs(0, n);
    cout << res << '\n';
    for(int i : ret) {
        cout << i << " ";
    }
    return 0;
}