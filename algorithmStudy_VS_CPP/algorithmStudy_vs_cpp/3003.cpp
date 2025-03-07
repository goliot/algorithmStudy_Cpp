#include <iostream>
using namespace std;

int main()
{
	int right[6] = { 1, 1, 2, 2, 2, 8 };
	int x;
	for (int i = 0; i < 6; i++)
	{
		cin >> x;

		cout << right[i] - x << " ";
	}

	return 0;
}