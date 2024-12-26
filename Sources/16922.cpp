#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[4] = {1, 5, 10, 50};
bool visited[1001] = {false, }; // 입력 범위에서 만들어지는 가장 큰 수는 1000
int res = 0;

void dfs(int cnt, int idx, int total) {
    if(cnt == n) {
        if(!visited[total]) {
            visited[total] = true;
            res++;
        }
        return;
    }
    for(int i=idx; i<4; i++) {
        dfs(cnt + 1, i, total + num[i]);
    }
}

int main() {
    cin >> n;
    dfs(0, 0, 0);
    cout << res;

    return 0;
}