#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
vector<int> cur;

void dfs(int idx) {
    if(idx == m) {
        for(int i : cur) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        cur.push_back(arr[i]);
        dfs(idx + 1);
        cur.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    dfs(0);

    return 0;
}