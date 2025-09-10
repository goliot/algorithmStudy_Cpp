#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, res = 0;
char c;
int dist[51][51];
int friendCount[51] = { 0, };

void floyd() 
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	fill(&dist[0][0], &dist[0][0] + 51 * 51, INT_MAX);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> c;
			if (c == 'Y')
			{
				dist[i][j] = 1;
			}
			if (i == j)
			{
				dist[i][j] = 0;
			}
		}
	}

	floyd();
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (dist[i][j] <= 2 && i != j) cnt++;
		}
		res = max(cnt, res);
	}
	cout << res;
	
	return 0;
}