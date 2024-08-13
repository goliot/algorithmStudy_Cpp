#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int parent[51];
vector<int> know;
vector<vector<int> > party(51);

int find(int x) {
    if(parent[x] == x) return x;
    return x = find(parent[x]);
}

void unionParent(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    while(k--) {
        int t;
        cin >> t;
        know.push_back(t);
    }

    for(int i=1; i<=n; i++) parent[i] = i;
    for(int i=0; i<m; i++) {
        int p;
        cin >> p;
        int num;
        int prev;
        for(int j=0; j<p; j++) {
            if(j>=1) {
                prev = num;
                cin >> num;
                unionParent(prev, num);
            }
            else {
                cin >> num;
            }
            party[i].push_back(num);
        }
    }
    for(auto& list : party) {
        bool flag = false;
        for(auto& person : list) {
            if(flag) break;
            for(auto& t : know) {
                if(find(person) == find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if(flag) m--;
    }
    cout << m;


    return 0;
}
