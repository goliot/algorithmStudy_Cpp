#include <iostream>
#include <vector>
using namespace std;

int n, x, cnt = 0, root, toErase;
vector<int> tree[51];

void dfs(int cur) {
	if (cur == toErase) {
		return;
	}
	bool isLeaf = true;
	for (int child : tree[cur])
	{
		if (child == toErase) continue;
		isLeaf = false;
		dfs(child);
	}

	if (isLeaf) cnt++;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == -1) {
			root = i;
		}
		else {
			tree[x].push_back(i);
		}


	}
	cin >> toErase;

	if (toErase == root) {
		cout << 0;
	}
	else {
		dfs(root);
		cout << cnt;
	}

	return 0;
}