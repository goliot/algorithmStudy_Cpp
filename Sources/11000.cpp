#include <iostream> //11000
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for(int i=1; i<n; i++) {
        pq.push(v[i].second);
        if(pq.top() <= v[i].first) pq.pop();
    }

    cout << (int)pq.size();

    return 0;
}
