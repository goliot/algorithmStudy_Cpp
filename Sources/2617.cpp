#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt = 0, rCnt = 0, res = 0;
int goalNum;
vector<vector<int> > graph;
vector<vector<int> > rGraph;
bool visited[100] = {false, };
bool rVisited[100] = {false, };

void dfs(const vector<vector<int> >& g, bool* v, int cur, int& count)
{
    v[cur] = true;
    for(int i=0; i<g[cur].size(); i++)
    {
        int next = g[cur][i];
        if(!v[next])
        {
            count++;
            dfs(g, v, next, count);
        }
    }
}

void clear()
{
    cnt = 0;
    rCnt = 0;
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
        rVisited[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<int>(0, 0));
    rGraph.assign(n + 1, vector<int>(0, 0));
    for(int i=0; i<m; i++)
    {
        int heavy, light;
        cin >> heavy >> light;
        graph[heavy].push_back(light);
        rGraph[light].push_back(heavy);
    }

    goalNum = (n + 1) / 2;

    for(int i=1; i<=n; i++)
    {
        clear();

        dfs(graph, visited, i, cnt);
        dfs(rGraph, rVisited, i, rCnt);

        if(cnt >= goalNum || rCnt >= goalNum)
        {
            res++;
        }
    }

    cout << res;

    return 0;
}