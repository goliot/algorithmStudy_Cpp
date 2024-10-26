#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<> > q;
    int n, x;

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> x;
            q.push(x);
            if(q.size() > n) q.pop();
        }
    }
    cout << q.top();

    return 0;
}