#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string nums = "22233344455566677778889999";

	string input;
	int res = 0;
	cin >> input;

	for (char c : input)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (c == s[i])
			{
				res += nums[i] - '0' + 1;
			}
		}
	}

	cout << res;

	return 0;
}