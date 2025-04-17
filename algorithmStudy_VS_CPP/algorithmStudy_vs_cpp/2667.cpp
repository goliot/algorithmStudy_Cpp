#include <iostream> //2667
#include <queue>
#include <algorithm>
using namespace std;

int n, cnt = 0;
string arr[26];
bool visited[26][26] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> res;
queue<pair<int, int> > q;

void bfs(int x, int y) {
    q.emplace(x, y);
    visited[x][y] = true;
    cnt++;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(0 <= nx && 0 <= ny && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] == '1') {
                q.emplace(nx, ny);
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j]=='1' && !visited[i][j]) {
                cnt = 0;
                bfs(i, j);
                res.push_back(cnt);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for(int i : res) {
        cout << i << '\n';
    }
}