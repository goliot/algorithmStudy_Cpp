#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> s;
char dist[5][5];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int cnt, int x, int y, int cur)
{
	if (cnt == 6) {
		s.insert(cur);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
		{
			continue;
		}

		dfs(cnt + 1, nx, ny, cur * 10 + dist[nx][ny]);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> dist[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(1, i, j, dist[i][j]);
		}
	}

	cout << s.size();

	return 0;
}