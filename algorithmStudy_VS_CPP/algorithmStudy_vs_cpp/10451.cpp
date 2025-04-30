#include <iostream>
using namespace std;

int v[1001];
bool visited[1001] = {false, };

void reset(int n) {
	for (int i = 0; i <= n; i++) {
		visited[i] = false;
		v[i] = 0;
	}
}

void dfs(int start) {
	visited[start] = true;
	if (!visited[v[start]])
	{
		dfs(v[start]);
	}
}

int main() 
{
	int t, n, x;
	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> n;
		reset(n);

		for (int i = 1; i <= n; i++) {
			cin >> x;
			v[i] = x;
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i])
			{
				dfs(i);
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}