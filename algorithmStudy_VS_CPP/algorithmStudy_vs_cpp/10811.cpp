#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[101] = { 0, };

	int n, m, a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;
	}

	while (m--)
	{
		cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}