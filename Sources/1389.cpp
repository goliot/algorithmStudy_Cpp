#include <iostream> //1389
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> a[101];
int res[101][101];
queue<int> q;

void bfs(int start) {
    int v[101] = {0, };
    q.push(start);
    v[start] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++) {
            int idx = a[x][i];
            if(v[idx] == 0) {
                v[idx] = 1;
                q.push(idx);
                res[idx][start] = res[x][start] + 1;
                res[start][idx] = res[start][x] + 1;
            }
        }
    }
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    int sum = 0, result = 0, min = INT_MAX;
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            res[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++) {
        bfs(i);
    }

    for(int i=1; i<=n; i++) {
        sum = 0;
        for(int j=1; j<=n; j++) {
            sum += res[i][j];
        }
        if(min > sum) {
            min = sum;
            result = i;
        }
    }

    cout << result;

    return 0;
}