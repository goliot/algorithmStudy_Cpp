#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, res = 0;
char c;
int board[51][51];
int friendCount[51] = { 0, };

void floyd() 
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][k] != INT_MAX && board[k][j] != INT_MAX)
				{
					board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	fill(&board[0][0], &board[0][0] + 51 * 51, INT_MAX);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> c;
			if (c == 'Y')
			{
				board[i][j] = 1;
			}
			if (i == j)
			{
				board[i][j] = 0;
			}
		}
	}

	floyd();
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= 2 && i != j) cnt++;
		}
		res = max(cnt, res);
	}
	cout << res;
	
	return 0;
}