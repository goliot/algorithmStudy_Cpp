#include <iostream>
using namespace std;

int main() {
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
		}
		cout << n - 1 << '\n';
	}

	return 0;
}