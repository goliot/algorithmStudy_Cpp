#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[3];
int check[201][201][201];
vector<int> v;

void bfs() {
    queue<tuple<int, int, int> > q;
    q.emplace(0, 0, a[2]);
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if(check[x][y][z]) continue;
        check[x][y][z] = 1;
        if(!x) v.push_back(z);

        if(x+y > a[1]) q.emplace(x-(a[1]-y), a[1], z);
        else q.emplace(0, x+y, z);

        if(x+z>a[2]) q.emplace(x-(a[2] - z), y, a[2]);
        else q.emplace(0, y, x+z);

        if(x+y>a[0]) q.emplace(a[0],y-(a[0]-x),z);
        else q.emplace(x+y, 0, z);

        if(y+z>a[2]) q.emplace(x,y-(a[2]-z),a[2]);
        else q.emplace(x, 0, y+z);

        if(z+x>a[0]) q.emplace(a[0], y, z-(a[0]-x));
        else q.emplace(x+z, y, 0);

        if(z+y>a[1]) q.emplace(x, a[1], z-(a[1]-y));
        else q.emplace(x, z+y, 0);
    }
}

int main() {
    for(int & i : a)
        cin >> i;
    bfs();
    sort(v.begin(), v.end());
    for(auto e : v) cout << e << ' ';

    return 0;
}