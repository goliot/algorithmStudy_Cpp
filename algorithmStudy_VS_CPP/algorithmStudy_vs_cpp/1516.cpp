#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
    int n;
    cin >> n;

    vector<int> buildTime(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    vector<int> dp(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        buildTime[i] = t;
        dp[i] = t;

        int b;
        cin >> b;
        while (b != -1)
        {
            graph[b].push_back(i);
            indegree[i]++;

            cin >> b;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            dp[next] = max(dp[next], dp[cur] + buildTime[next]);
            indegree[next]--;

            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << dp[i] << '\n';
    }

    return 0;
}