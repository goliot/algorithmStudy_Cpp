#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int s[14];
vector<int> res;

void dfs(int start, int cnt) {
    if(cnt == 6) {
        for(int n : res) {
            cout << n << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<k; i++) {
        res.push_back(s[i]);
        dfs(i + 1, cnt + 1);
        res.pop_back();
    }
}

int main() {
    while(true) {
        cin >> k;
        if(k == 0) break;

        fill(begin(s), end(s), 0);

        for(int i=0; i<k; i++) {
            cin >> s[i];
        }
        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}