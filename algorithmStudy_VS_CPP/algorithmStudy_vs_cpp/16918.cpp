#include <iostream>
#include <queue>
using namespace std;

int r, c, n;
char board[201][201];
int explodeTime[201][201];
int timer = 2;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void installBomb() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] != 'O')
			{
				board[i][j] = 'O';
				explodeTime[i][j] = timer + 3;
			}
		}
	}
}

void explode() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (explodeTime[i][j] == timer)
			{
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c || board[nx][ny] == '.')
					{
						continue;
					}

					board[nx][ny] = '.';
				}
				board[i][j] = '.';
				explodeTime[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> r >> c >> n;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O')
			{
				explodeTime[i][j] = 3;
			}
		}
	}

	while (timer <= n)
	{
		if (timer % 2 == 0)
		{
			installBomb();
		}
		else 
		{
			explode();
		}
		timer++;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}