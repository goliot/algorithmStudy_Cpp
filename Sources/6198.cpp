#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long res = 0;
    cin >> n;
    vector<int> v(n, 0);
    stack<int> s;

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    for(int i=0; i<n; i++)
    {
        if(s.empty())
        {
            s.push(v[i]);
            continue;
        }

        while(!s.empty() && s.top() <= v[i])
        {
            s.pop();
        }

        res += s.size();

        s.push(v[i]);
    }

    cout << res;

    return 0;
}