#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool visited[10];

void dfs(int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << num[arr[i]] << " ";
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i] && tmp!=num[i]) {
            arr[k] = i;
            tmp = num[i];
            visited[i] = true;
            dfs(k+1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num, num+n);
    dfs(0);

    return 0;
}
