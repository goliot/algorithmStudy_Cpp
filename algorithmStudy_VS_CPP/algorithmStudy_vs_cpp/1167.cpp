#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > tree[100001];
int res = 0, maxNode;
int visited[100001] = {-1, };

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<tree[x].size(); i++) {
            if(visited[tree[x][i].first]==-1) {
                visited[tree[x][i].first] = visited[x] + tree[x][i].second;
                q.push(tree[x][i].first);

                if(res < visited[tree[x][i].first]) {
                    res = visited[tree[x][i].first];
                    maxNode = tree[x][i].first;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int from, to , weight;
        cin >> from;
        while(true) {
            cin >> to;
            if(to == -1) break;
            else cin >> weight;

            tree[from].emplace_back(to, weight);
        }
    }

    memset(visited, -1, sizeof(visited));
    bfs(1);

    memset(visited, -1, sizeof(visited));
    bfs(maxNode);

    cout << res;

    return 0;
}