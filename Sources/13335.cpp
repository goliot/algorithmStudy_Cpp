#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> trucks;
int n, w, l, x;

int sol() {
    int curWeight = 0, idx = 0;
    int res = 0;
    while(true) {
        if(idx == trucks.size()) {
            res += w;
            break;
        }

        int tmp = trucks[idx];
        if(q.size() == w) {
            curWeight -= q.front();
            q.pop();
        }
        if(curWeight + tmp <= l) {
            curWeight += tmp;
            q.push(tmp);
            idx++;
        }
        else {
            q.push(0);
        }
        res++;
    }

    return res;
}

int main() {
    cin >> n >> w >> l;
    for(int i=0; i<n; i++) {
        cin >> x;
        trucks.push_back(x);
    }
    cout << sol();

    return 0;
}