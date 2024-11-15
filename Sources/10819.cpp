#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int n, res = INT_MIN;
int arr[9];
bool visited[9] = {false, };
vector<int> cur;

void dfs(int idx) {
    if(idx == n) {
        int sum = 0;
        for(int i=0; i<cur.size() - 1; i++) {
            sum += abs(cur[i] - cur[i + 1]);
        }
        res = max(res, sum);
        return;
    }
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            cur.push_back(arr[i]);
            dfs(idx + 1);
            cur.pop_back();
            visited[i] = false;
        }
    };
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << res;

    return 0;
}