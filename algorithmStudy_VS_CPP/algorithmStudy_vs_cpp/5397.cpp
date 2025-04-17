#include <iostream>
#include <string>
#include <list>
using namespace std;

int t;
string s;

string solve(const string& before)
{
    list<char> res;
    auto cursor = res.begin();

    for(char c : before)
    {
        if(c == '<')
        {
            if(cursor != res.begin())
                cursor--;
        }
        else if(c == '>')
        {
            if(cursor != res.end())
                cursor++;
        }
        else if(c == '-')
        {
            if(cursor != res.begin())
            {
                cursor--;
                cursor = res.erase(cursor);
            }
        }
        else
        {
            res.insert(cursor, c);
        }
    }

    string result(res.begin(), res.end());
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> s;
        cout << solve(s) << '\n';
    }

    return 0;
}