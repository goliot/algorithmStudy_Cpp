#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
vector<int> cur;
bool visited[9] = {false, };

void dfs(int idx) {
    if(idx == m) {
        for(int i=0; i<cur.size() - 1; i++) {
            if(cur[i] > cur[i+1]) return;
        }
        for(int i : cur) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++) {
        if(visited[i] || (i > 0 && arr[i] == arr[i-1] && !visited[i-1]))
            continue;
        visited[i] = true;
        cur.push_back(arr[i]);
        dfs(idx + 1);
        cur.pop_back();
        visited[i] = false;
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