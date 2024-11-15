#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n ,d, from, to, dis;

int main() {
    cin >> n >> d;
    vector<int> map(d+1, INT_MAX);
    vector<pair<int, int> > shortCut[10001];
    for(int i=0; i<n; i++) {
        cin >> from >> to >> dis;
        shortCut[to].emplace_back(from, dis);
    }
    map[0] = 0;
    for(int i=1; i<=d; i++) {
        if(shortCut[i].empty())
            map[i] = map[i-1] + 1;
        else {
            for(auto v : shortCut[i])
                map[i] = min(map[i], min(map[i-1]+1, map[v.first] + v.second));
        }
    }
    cout << map[d];

    return 0;
}