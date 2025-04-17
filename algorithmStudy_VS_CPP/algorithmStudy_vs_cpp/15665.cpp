#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, a;
vector<int> arr;
int res[8];
bool visited[10001];

void dfs(int cnt) {
    if(cnt == m) {
        for(int i=0; i<m; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<arr.size(); i++) {
        res[cnt] = arr[i];
        dfs(cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        cin >> a;
        if(!visited[a]) {
            arr.push_back(a);
            visited[a] = true;
        }
    }
    sort(arr.begin(), arr.end());
    dfs(0);

    return 0;
}