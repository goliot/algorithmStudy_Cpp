#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string inputString;
int maxNum, len;
bool visited[51] = {false, };
vector<int> v;

void dfs()
{
    stack<pair<int, vector<int> > > s;
    s.push({0, {}});

    while(!s.empty())
    {
        int n = s.top().first;
        vector<int> curV = s.top().second;
        s.pop();

        if(n == len)
        {
            for(int i : curV)
            {
                cout << i << " ";
            }
            exit(0);
        }

        string sTmp;
        int num;
        for(int i=n; i<=n+1; i++)
        {
            sTmp += inputString[i];
            num = stoi(sTmp);

            if(num > maxNum || visited[num] || n >= len)
                continue;

            visited[num] = true;
            curV.push_back(num);

            s.emplace(i + 1, curV);

            visited[num] = false;
            curV.pop_back();
        }
    }
}

int main()
{
    cin >> inputString;
    len = (int)inputString.length();
    if(len > 9)
    {
        maxNum = 9 + (len - 9) / 2;
    }
    else
    {
        maxNum = len;
    }

    dfs();

    return 0;
}