#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int arr[31] = { 0, };

	for (int i = 1; i <= 30; i++)
	{
		arr[i] = i;
	}

	int x;
	for (int i = 0; i < 28; i++)
	{
		cin >> x;
		arr[x] = 0;
	}
	for (int i = 1; i <= 30; i++)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] << '\n';
		}
	}

	return 0;
}