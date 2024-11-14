#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[10];
bool visited[10];

void dfs(int idx) {
    if(idx == n) {
        for(int i=0; i<n; i++) {
            cout << num[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            num[idx] = i;
            dfs(idx + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);

    return 0;
}