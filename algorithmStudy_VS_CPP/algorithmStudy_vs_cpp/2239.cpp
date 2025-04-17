#include <iostream>
#include <algorithm>
using namespace std;

int map[10][10];
bool row[10][10] = {false, };
bool col[10][10] = {false, };
bool square[10][10] = {false, };
bool solved = false; // 해가 이미 나왔는지 확인하는 변수

void dfs(int cnt) {
    if (cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j];
            }
            cout << '\n';
        }
        solved = true; // 정답을 찾았으므로 플래그 설정
        return;
    }

    int x = cnt / 9;
    int y = cnt % 9;
    if (map[x][y] != 0) {
        dfs(cnt + 1); // 이미 채워져 있는 칸은 다음 칸으로 이동
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!row[x][i] && !col[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                map[x][y] = i;
                if (solved) return; // 정답을 찾으면 모든 재귀에서 빠져나옴
                dfs(cnt + 1);
                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
}

int main() {
    char c;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> c;
            map[i][j] = c - '0';
            if (map[i][j] != 0) {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                square[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }

    dfs(0);
    return 0;
}
