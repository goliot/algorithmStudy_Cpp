#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> > v;
    vector<int> sol(n);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        sol[v[i].second] = i;
    }
    for(int i : sol) {
        cout << i << ' ';
    }

    return 0;
}