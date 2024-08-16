#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int first[9];
int arr[9];
bool visited[9];

void dfs(int num, int k) {
    if(k == m) {
        for(int i=0; i<m; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    else {
        for(int i=num; i<=n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                arr[k] = first[i-1];
                dfs(i+1, k+1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> first[i];
    }
    sort(first, first + n);
    dfs(1, 0);

    return 0;
}