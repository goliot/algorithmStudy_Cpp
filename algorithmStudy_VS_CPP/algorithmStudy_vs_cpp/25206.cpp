#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	string sub, num, grade;

	unordered_map<char, int> m;
	m['A'] = 4;
	m['B'] = 3;
	m['C'] = 2;
	m['D'] = 1;

	float sum = 0;
	float numSum = 0;
	float avg = 0;

	for (int i = 0; i < 20; i++) 
	{
		float tmp = 0;

		cin >> sub >> num >> grade;
		if (grade[0] == 'P')
		{
			continue;
		}
		numSum += stof(num);
		if (grade[0] == 'F')
		{
			continue;
		}

		tmp += m[grade[0]];
		if (grade[1] == '+')
			tmp += 0.5f;
		sum += tmp * stof(num);
	}

	cout << sum / numSum;

	return 0;
}