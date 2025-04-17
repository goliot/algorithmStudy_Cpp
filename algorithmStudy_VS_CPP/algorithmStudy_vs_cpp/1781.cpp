#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int n, deadline, cup;
    vector<pair<int, int> > v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> deadline >> cup;
        v.emplace_back(deadline, cup);
        v[i].first--;
    }
    sort(v.begin(), v.end(), cmp);
    long long res = 0;
    priority_queue<int> q;
    for(int i=n-1, j=0; i>=0; i--) {
        while(j < n && i == v[j].first) {
            q.push(v[j].second);
            j++;
        }
        if(!q.empty()) {
            res += q.top();
            q.pop();
        }
    }

    cout << res;

    return 0;
}