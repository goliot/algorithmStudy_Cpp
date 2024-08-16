#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int k;
int num[6];
int v[13];

void dfs(int start, int depth) {
    if(depth == 6) {
        for(int i : num) {
            cout << i << ' ';
        }
        cout << endl;

        return;
    }
    else {
        for(int i=start; i<k; i++) {
            num[depth] = v[i];
            dfs(i+1, depth+1);
        }
    }
}

int main() {
    while(true) {
        cin >> k;
        if(k == 0) return 0;
        for(int i=0; i<k; i++) {
            cin >> v[i];
        }
        dfs(0, 0);
        cout << endl;
    }
}