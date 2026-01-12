#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int num, int cnt)
{
    if (cnt == N)
    {
        if (isPrime(num))
        {
            cout << num << '\n';
        }
        return;
    }

    for (int i = 1; i < 10; ++i)
    {
        if (i % 2 == 0)
        {
            continue;
        }

        if (isPrime(num * 10 + i))
        {
            dfs(num * 10 + i, cnt + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> N;
	
    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

	return 0;
}