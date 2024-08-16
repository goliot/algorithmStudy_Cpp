#include <iostream>
using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
bool selected[5];

void dfs(int idx, int cnt) {
    if(cnt == 3) {
        for(int i=0; i<5; i++) {
            if(selected[i])
                cout << arr[i] << ' ';
        }
        cout << endl;
    }

    for(int i=idx; i<5; i++) {
        if(selected[i]) continue;
        selected[i] = true;
        dfs(i, cnt + 1);
        selected[i] = false;
    }
}

int main() {
    dfs(0, 0);
    return 0;
}