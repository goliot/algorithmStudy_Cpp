#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, x;
	cin >> n >> m;

	vector<vector<int> > arr(n, vector<int>(m, 0));
	vector<vector<int> > arr2(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			arr[i][j] = x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> x;
			arr2[i][j] = x;

			cout << arr[i][j] + arr2[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}