#include <iostream>
#include <vector>
using namespace std;

int testCase;
int v, e;
vector<vector<int> > graph;
vector<int> visited;

void dfs(int cur)
{
    if(!visited[cur]) visited[cur] = 1;

    for(int i=0; i<graph[cur].size(); i++)
    {
        int next = graph[cur][i];

        if(!visited[next])
        {
            if (visited[cur] == 1) visited[next] = 2;
            else if(visited[cur] == 2) visited[next] = 1;
            dfs(next);
        }
    }
}

bool isBipartite()
{
    for(int cur = 1; cur <= v; cur++)
    {
        for(int i=0; i<graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if(visited[cur] == visited[next])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> testCase;
    while(testCase--)
    {
        string answer;

        cin >> v >> e;
        graph.assign(v+1, vector<int>(0, 0));
        visited.assign(v+1, false);

        for(int i=0; i<e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i=1; i<=v; i++)
        {
            if(!visited[i]) dfs(i);
        }

        answer = isBipartite() ? "YES" : "NO";
        cout << answer << '\n';
    }

    return 0;
}