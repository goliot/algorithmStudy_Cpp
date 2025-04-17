#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int score[51] = {0, };
int dist[51][51];

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i == j) continue;
            else dist[i][j] = INT_MAX;
        }
    }

    int a, b;
    while(true)
    {
        cin >> a >> b;

        if(a == -1 && b == -1) break;

        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int member = -1;
    for(int i=1; i<=n; i++)
    {
        int m = 0;
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j] > m)
                m = dist[i][j];
        }
        score[i] = m;
        if(member > m || member == -1) member = m;
    }

    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(score[i] == member) cnt++;
    }

    cout << member << " " << cnt << '\n';
    for(int i=1; i<=n; i++)
    {
        if(score[i] == member) cout << i << " ";
    }

    return 0;
}