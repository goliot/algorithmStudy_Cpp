#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> meetings(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> meetings[i].second >> meetings[i].first;
	}

	sort(meetings.begin(), meetings.end());

	int count = 0;
	int end = -1;

	for (int i = 0; i < n; ++i)
	{
		if (meetings[i].second >= end)
		{
			end = meetings[i].first;
			count++;
		}
	}

	cout << count;
		
	return 0;
}