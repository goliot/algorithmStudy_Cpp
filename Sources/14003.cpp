#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLIS(const vector<pair<int, int> >& v) {
    vector<int> res;
    vector<int> index;
    for(int i=0; i<v.size(); i++) {

    }

    return res;
}

int main() {
    int n, x;
    vector<pair<int, int> > v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.emplace_back(x, i);
    }

    vector<int> res = findLIS(v);
    cout << res.size() << '\n';
    for(int i : res) {
        cout << i << " ";
    }

    return 0;
}