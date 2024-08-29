#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, answer = 0;
    int prefix[10001] = {0, };
    cin >> n >> m;
    for(int i=0, x; i<n; i++) {
        if(i != 0) {
            cin >> x;
            prefix[i] = x + prefix[i-1];
        }
        else {
            cin >> prefix[0];
        }
    }
    for(int i=n; i>=0; i--) {
        if(prefix[i] == m) answer++;
        else {
            for(int j=i-1; j>=0; j--) {
                if(prefix[i] - prefix[j] == m) answer++;
            }
        }
    }

    cout << answer;
    return 0;
}