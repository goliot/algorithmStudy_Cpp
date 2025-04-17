#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
int num;
string team, name;

int main()
{
    map<string, vector<string> > dic;

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> team;
        cin >> num;
        for(int j=0; j<num; j++)
        {
            cin >> name;
            dic[team].push_back(name);
        }
    }

    string prob;
    int cate;

    for(int i=0; i<m; i++)
    {
        cin >> prob;
        cin >> cate;

        if(cate == 1)
        {
            for(auto & it : dic)
            {
                if(find(it.second.begin(), it.second.end(), prob) != it.second.end())
                {
                    cout << it.first << '\n';
                }
            }
        }
        else
        {
            auto it = dic.find(prob);
            sort(it->second.begin(), it->second.end());

            for(const string& s : it->second)
            {
                cout << s << '\n';
            }
        }
    }

    return 0;
}