#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n;

    priority_queue<int> rightMax;
    priority_queue<int, vector<int>, greater<> > leftMin;

    for(int i=0; i<n; i++) {
        cin >> k;

        if(rightMax.empty() || k <= rightMax.top()) {
            rightMax.push(k);
        }
        else leftMin.push(k);

        if(rightMax.size() > leftMin.size() + 1) {
            leftMin.push(rightMax.top());
            rightMax.pop();
        } else if(leftMin.size() > rightMax.size()) {
            rightMax.push(leftMin.top());
            leftMin.pop();
        }

        cout << rightMax.top() << '\n';
    }

    return 0;
}