#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    int k, l;
    string x;
    cin >> k >> l;
    unordered_map<string, int> m;
    for(int i=0; i<l; i++) {
        cin >> x;
        m[x] = i;
    }
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<min(k, (int)v.size()); i++) {
        cout << v[i].first << '\n';
    }

    return 0;
}