#include <iostream>
#include <vector>
using namespace std;

int n, r, q, u, v;
vector<int> tree[100001];
int subSize[100001] = { 0, };
bool visited[100001] = { false, };

int dfs(int cur) {
	visited[cur] = true;
	subSize[cur] = 1;
	for (int child : tree[cur]) {
		if (!visited[child])
		{
			subSize[cur] += dfs(child);
		}
	}
	return subSize[cur];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> r >> q;
	for (int i = 0; i < n-1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(r);

	while (q--)
	{
		cin >> u;
		cout << subSize[u] << '\n';
	}

	return 0;
}