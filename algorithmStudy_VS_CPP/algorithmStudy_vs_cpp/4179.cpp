#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
char map[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int> > fire;
queue<pair<int, int> > player;

void moveFire() {
    int cnt = (int)fire.size();
    for(int i=0; i<cnt; i++) {
        pair<int, int> cur = fire.front();
        fire.pop();
        for(int j=0; j<4; j++) {
            int nx = dx[j] + cur.first;
            int ny = dy[j] + cur.second;

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(map[nx][ny] != '.') continue;

            map[nx][ny] = 'F';
            fire.emplace(nx, ny);
        }
    }
}

int movePlayer() {
    int time = 0;
    while(!player.empty()) {
        time++;
        moveFire();
        int cnt = (int)player.size();
        for(int i=0; i<cnt; i++) {
            pair<int, int> cur = player.front();
            player.pop();
            for(int j=0; j<4; j++) {
                int nx = dx[j] + cur.first;
                int ny = dy[j] + cur.second;
                if(nx < 0 || ny < 0 || nx >= h || ny >= w)
                    return time;
                if(map[nx][ny] != '.') continue;

                map[nx][ny] = 'J';
                player.emplace(nx, ny);
            }
        }
    }

    return -1;
}

int main() {
    cin >> h >> w;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'F') fire.emplace(i, j);
            else if(map[i][j] == 'J') player.emplace(i, j);
            else continue;
        }
    }

    int res = movePlayer();
    if(res == -1) cout << "IMPOSSIBLE" << '\n';
    else cout << res << '\n';

    return 0;
}