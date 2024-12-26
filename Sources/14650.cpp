#include <iostream>
#include <stack>
using namespace std;

int n;
int res = 0;

struct State {
    int cnt;
    int total;
    bool isZero;
};

void dfs() {
    stack<State> s;
    s.push({0, 0, true});

    while(!s.empty()) {
        State cur = s.top();
        s.pop();

        if(cur.cnt == n) {
            if(cur.total % 3 == 0) {
                res++;
            }
            continue;
        }

        for(int i=0; i<3; i++) {
            if(cur.isZero && i == 0)
                continue;

            s.push({cur.cnt + 1, cur.total + i, false});
        }
    }
}

int main() {
    cin >> n;
    dfs();
    cout << res;

    return 0;
}