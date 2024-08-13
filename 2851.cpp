#include <iostream>
using namespace std;

int score[11];
int pre[11] = {0, };

int main() {
    for(int i=1; i<=10; i++) {
        cin >> score[i];
        pre[i] = pre[i-1] + score[i];
    }
    if(pre[10] < 100) {
        cout << pre[10];
        return 0;
    }
    for(int i=1; i<=10; i++) {
        if(pre[i] > 100) {
            int ans = pre[i] - 100 > 100 - pre[i-1] ? pre[i-1] : pre[i];
            if(pre[i] - 100 == 100-pre[i-1]) ans = pre[i];
            cout << ans;

            return 0;
        }
    }
}