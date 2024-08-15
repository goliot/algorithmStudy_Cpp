#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int cnt) {
    if(cnt == m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    dfs(0);
}