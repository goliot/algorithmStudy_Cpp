#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int answer = 0;
int map[5][5];
bool selected[25];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool moreThanFour() {
    int cnt = 0;
    for(int i=0; i<25; i++) {
        if(selected[i]) {
            int x = i / 5;
            int y = i % 5;

            if(map[x][y] == 2) cnt++;
        }
    }
    return cnt >= 4;
}

bool close() {
    queue<pair<int, int> > q;
    bool check_select[5][5] = {false, };
    bool visited[5][5] = {false, };

    int tmp = 0;
    for(int i=0; i<25; i++) {
        if(selected[i]) {
            int x = i / 5;
            int y = i % 5;
            check_select[x][y] = true;
            if(tmp == 0) {
                q.emplace(x, y);
                visited[x][y] = true;
                tmp++;
            }
        }
    }

    int cnt = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(cnt == 7) {
            return true;
        }
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || !check_select[nx][ny] || visited[nx][ny])
                continue;

            visited[nx][ny] = true;
            q.emplace(nx, ny);
            cnt++;
        }
    }

    return false;
}

void dfs(int idx, int cnt) {
    if(cnt == 7) {
        if(moreThanFour()) {
            if(close()) answer++;
        }
        return;
    }
    else {
        for(int i=idx; i<25; i++) {
            if(selected[i]) continue;
            selected[i] = true;
            dfs(i, cnt+1);
            selected[i] = false;
        }
    }
}

int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            char c;
            cin >> c;
            if(c == 'Y') map[i][j] = 1;
            else map[i][j] = 2;
        }
    }

    dfs(0, 0);
    cout << answer;

    return 0;
}