#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	vector<int> v(n + 1, 0);
	for (int i=1; i<=n; i++)
	{
		v[i] = i;
	}

	while (m--)
	{
		cin >> a >> b;

		swap(v[a], v[b]);
	}

	for (int i=1; i<=n; i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}