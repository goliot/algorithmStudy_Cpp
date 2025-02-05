#include <iostream>
#include <vector>
using namespace std;

int n, m, res = 0;
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
        fill(visited, visited + n + 1, false);
        fill(rVisited, rVisited + n + 1, false);

        int cnt = 0, rCnt = 0;

        dfs(graph, visited, i, cnt); //자기보다 가벼운 구슬 수
        dfs(rGraph, rVisited, i, rCnt); //자기보다 무거운 구슬 수

        if(cnt >= goalNum || rCnt >= goalNum)
        {
            res++;
        }
    }

    cout << res;

    return 0;
}