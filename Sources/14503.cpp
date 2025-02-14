#include <iostream>
#include <vector>
using namespace std;

int n, m, r, c, d;
int map[51][51];
bool visited[51][51] = {false, };
int res = 0;
pair<int, int> cur;

void simulate()
{
    // 북, 동, 남, 서 방향 (반시계 방향 순서)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (true)
    {
        // 1. 현재 칸 청소
        if (!visited[cur.first][cur.second])
        {
            visited[cur.first][cur.second] = true;
            res++;
        }

        bool cleaned = false;
        for (int i = 0; i < 4; i++)
        {
            // 2. 반시계 방향으로 회전
            d = (d + 3) % 4;
            int nr = cur.first + dr[d];
            int nc = cur.second + dc[d];

            // 3. 청소되지 않은 빈 칸이면 이동 후 반복
            if (map[nr][nc] == 0 && !visited[nr][nc])
            {
                cur = {nr, nc};
                cleaned = true;
                break;
            }
        }

        // 4. 네 방향 모두 청소되었거나 벽일 경우
        if (!cleaned)
        {
            int back_dir = (d + 2) % 4; // 후진 방향
            int br = cur.first + dr[back_dir];
            int bc = cur.second + dc[back_dir];

            if (map[br][bc] == 1) // 후진 불가능하면 종료
                break;

            cur = {br, bc}; // 후진 가능하면 후진 후 반복
        }
    }

    cout << res << endl;
}


int main()
{
    cin >> n >> m;
    cin >> r >> c >> d;

    cur = {r, c};

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    simulate();

    return 0;
}


// l - d - r - u - l